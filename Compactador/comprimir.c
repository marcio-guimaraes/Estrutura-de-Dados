#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comprimir.h"

#define MAX_CODIGO 256

typedef struct No
{
    unsigned char caractere;
    int frequencia;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct FilaNo
{
    No *arvoreNo;
    struct FilaNo *prox;
} FilaNo;

typedef struct
{
    FilaNo *inicio;
} FilaPrioridade;

No *criarNo(unsigned char caractere, int frequencia);
void inserirFila(FilaPrioridade *fila, No *arvoreNo);
No *removerFila(FilaPrioridade *fila);
No *construirArvore(FilaPrioridade *fila);
void gerarCodigos(No *no, char *codigoAtual, int tamanho, char *codigos[256]);
void liberarArvore(No *no);
void escreverBit(FILE *arquivo, int bit, unsigned char *buffer, int *contador);
void finalizarEscrita(FILE *arquivo, unsigned char *buffer, int *contador);
void salvarArvore(No *no, FILE *arquivo, unsigned char *buffer, int *contador);

int comprimirArquivo(const char *entradaPath, const char *saidaPath)
{
    FILE *entrada = fopen(entradaPath, "r");
    if (!entrada)
        return 1;

    int repeticoes[256] = {0};
    int c;
    while ((c = fgetc(entrada)) != EOF)
        repeticoes[c]++;
    fclose(entrada);

    int totalCaracteres = 0;
    for (int i = 0; i < 256; i++)
        totalCaracteres += repeticoes[i];

    FilaPrioridade fila = {NULL};
    for (int i = 0; i < 256; i++)
    {
        if (repeticoes[i] > 0)
        {
            No *novo = criarNo((unsigned char)i, repeticoes[i]);
            inserirFila(&fila, novo);
        }
    }

    if (fila.inicio == NULL)
        return 1;

    No *raiz = construirArvore(&fila);

    char *codigos[256] = {0};
    char codigoAtual[MAX_CODIGO];
    gerarCodigos(raiz, codigoAtual, 0, codigos);

    FILE *saida = fopen(saidaPath, "wb");
    if (!saida)
    {
        liberarArvore(raiz);
        return 1;
    }

    fwrite(&totalCaracteres, sizeof(int), 1, saida);

    unsigned char buffer = 0;
    int contador = 0;

    salvarArvore(raiz, saida, &buffer, &contador);

    entrada = fopen(entradaPath, "r");
    if (!entrada)
    {
        fclose(saida);
        liberarArvore(raiz);
        return 1;
    }

    while ((c = fgetc(entrada)) != EOF)
    {
        char *codigo = codigos[c];
        for (int i = 0; codigo[i] != '\0'; i++)
            escreverBit(saida, codigo[i] - '0', &buffer, &contador);
    }

    finalizarEscrita(saida, &buffer, &contador);

    fclose(entrada);
    fclose(saida);

    liberarArvore(raiz);
    for (int i = 0; i < 256; i++)
        if (codigos[i])
            free(codigos[i]);

    return 0;
}

No *criarNo(unsigned char caractere, int frequencia)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->caractere = caractere;
    novo->frequencia = frequencia;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void inserirFila(FilaPrioridade *fila, No *arvoreNo)
{
    FilaNo *novo = (FilaNo *)malloc(sizeof(FilaNo));
    novo->arvoreNo = arvoreNo;
    novo->prox = NULL;
    if (fila->inicio == NULL || arvoreNo->frequencia < fila->inicio->arvoreNo->frequencia)
    {
        novo->prox = fila->inicio;
        fila->inicio = novo;
    }
    else
    {
        FilaNo *atual = fila->inicio;
        while (atual->prox != NULL && atual->prox->arvoreNo->frequencia <= arvoreNo->frequencia)
            atual = atual->prox;
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

No *removerFila(FilaPrioridade *fila)
{
    if (fila->inicio == NULL)
        return NULL;
    FilaNo *remover = fila->inicio;
    No *noRemovido = remover->arvoreNo;
    fila->inicio = remover->prox;
    free(remover);
    return noRemovido;
}

No *construirArvore(FilaPrioridade *fila)
{
    while (fila->inicio != NULL && fila->inicio->prox != NULL)
    {
        No *no1 = removerFila(fila);
        No *no2 = removerFila(fila);
        No *pai = criarNo(0, no1->frequencia + no2->frequencia);
        pai->esquerda = no1;
        pai->direita = no2;
        inserirFila(fila, pai);
    }
    return removerFila(fila);
}

void gerarCodigos(No *no, char *codigoAtual, int tamanho, char *codigos[256])
{
    if (no == NULL)
        return;
    if (no->esquerda == NULL && no->direita == NULL)
    {
        codigoAtual[tamanho] = '\0';
        codigos[no->caractere] = (char *)malloc(tamanho + 1);
        strcpy(codigos[no->caractere], codigoAtual);
        return;
    }
    codigoAtual[tamanho] = '0';
    gerarCodigos(no->esquerda, codigoAtual, tamanho + 1, codigos);
    codigoAtual[tamanho] = '1';
    gerarCodigos(no->direita, codigoAtual, tamanho + 1, codigos);
}

void liberarArvore(No *no)
{
    if (no == NULL)
        return;
    liberarArvore(no->esquerda);
    liberarArvore(no->direita);
    free(no);
}

void escreverBit(FILE *arquivo, int bit, unsigned char *buffer, int *contador)
{
    *buffer = (*buffer << 1) | (bit & 1);
    (*contador)++;
    if (*contador == 8)
    {
        fputc(*buffer, arquivo);
        *contador = 0;
        *buffer = 0;
    }
}

void finalizarEscrita(FILE *arquivo, unsigned char *buffer, int *contador)
{
    if (*contador > 0)
    {
        *buffer = *buffer << (8 - *contador);
        fputc(*buffer, arquivo);
    }
}

void salvarArvore(No *no, FILE *arquivo, unsigned char *buffer, int *contador)
{
    if (no == NULL)
        return;
    if (no->esquerda == NULL && no->direita == NULL)
    {
        escreverBit(arquivo, 1, buffer, contador);
        for (int i = 7; i >= 0; i--)
        {
            int bit = (no->caractere >> i) & 1;
            escreverBit(arquivo, bit, buffer, contador);
        }
    }
    else
    {
        escreverBit(arquivo, 0, buffer, contador);
        salvarArvore(no->esquerda, arquivo, buffer, contador);
        salvarArvore(no->direita, arquivo, buffer, contador);
    }
}
