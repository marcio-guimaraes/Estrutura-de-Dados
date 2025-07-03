#include <stdio.h>
#include <stdlib.h>
#include "descomprimir.h"

typedef struct No
{
    unsigned char caractere;
    struct No *esquerda;
    struct No *direita;
} No;

No *reconstruirArvore(FILE *arquivo, unsigned char *buffer, int *contador, int *fimArquivo);
void liberarArvoreDes(No *no);
int lerBit(FILE *arquivo, unsigned char *buffer, int *contador, int *fimArquivo);

int descomprimirArquivo(const char *entradaPath, const char *saidaPath)
{
    FILE *arquivo = fopen(entradaPath, "rb");
    if (!arquivo)
        return 1;

    int totalCaracteres = 0;
    fread(&totalCaracteres, sizeof(int), 1, arquivo);

    unsigned char buffer = 0;
    int contador = 0;
    int fimArquivo = 0;

    No *raiz = reconstruirArvore(arquivo, &buffer, &contador, &fimArquivo);
    if (!raiz)
    {
        fclose(arquivo);
        return 1;
    }

    FILE *saida = fopen(saidaPath, "w");
    if (!saida)
    {
        liberarArvoreDes(raiz);
        fclose(arquivo);
        return 1;
    }

    No *atual = raiz;
    int caracteresLidos = 0;

    while (caracteresLidos < totalCaracteres)
    {
        int bit = lerBit(arquivo, &buffer, &contador, &fimArquivo);
        if (fimArquivo)
            break;

        atual = (bit == 0) ? atual->esquerda : atual->direita;

        if (atual->esquerda == NULL && atual->direita == NULL)
        {
            fputc(atual->caractere, saida);
            atual = raiz;
            caracteresLidos++;
        }
    }

    fclose(arquivo);
    fclose(saida);
    liberarArvoreDes(raiz);

    return 0;
}

int lerBit(FILE *arquivo, unsigned char *buffer, int *contador, int *fimArquivo)
{
    if (*contador == 0)
    {
        int c = fgetc(arquivo);
        if (c == EOF)
        {
            *fimArquivo = 1;
            return 0;
        }
        *buffer = (unsigned char)c;
        *contador = 8;
    }
    int bit = (*buffer >> 7) & 1;
    *buffer <<= 1;
    (*contador)--;
    return bit;
}

No *reconstruirArvore(FILE *arquivo, unsigned char *buffer, int *contador, int *fimArquivo)
{
    int bit = lerBit(arquivo, buffer, contador, fimArquivo);
    if (*fimArquivo)
        return NULL;
    if (bit == 1)
    {
        unsigned char caractere = 0;
        for (int i = 0; i < 8; i++)
        {
            caractere <<= 1;
            caractere |= lerBit(arquivo, buffer, contador, fimArquivo);
        }
        No *no = (No *)malloc(sizeof(No));
        no->caractere = caractere;
        no->esquerda = NULL;
        no->direita = NULL;
        return no;
    }
    else
    {
        No *no = (No *)malloc(sizeof(No));
        no->esquerda = reconstruirArvore(arquivo, buffer, contador, fimArquivo);
        no->direita = reconstruirArvore(arquivo, buffer, contador, fimArquivo);
        return no;
    }
}

void liberarArvoreDes(No *no)
{
    if (!no)
        return;
    liberarArvoreDes(no->esquerda);
    liberarArvoreDes(no->direita);
    free(no);
}
