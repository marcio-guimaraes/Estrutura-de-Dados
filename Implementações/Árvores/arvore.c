#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

Arvore *cria_arvore()
{
    Arvore *raiz = (Arvore *)malloc(sizeof(Arvore));
    if (raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}

void libera_no(No *no)
{
    if (no == NULL)
        return;
    libera_no(no->esquerda);
    libera_no(no->direita);
    free(no);
}

No *remove_atual(No *atual)
{
    No *no1, *no2;
    if (atual->esquerda == NULL)
    {
        no2 = atual->direita;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esquerda;
    while (no2->direita != NULL)
    {
        no1 = no2;
        no2 = no2->direita;
    }
    if (no1 != atual)
    {
        no1->direita = no2->esquerda;
        no2->esquerda = atual->esquerda;
    }
    no2->direita = atual->direita;
    free(atual);
    return no2;
}

void libera_arvore(Arvore *raiz)
{
    if (raiz == NULL)
        return;
    libera_no(*raiz);
    free(raiz);
}

int esta_vazia(Arvore *raiz)
{
    if (raiz == NULL)
        return 1;
    return (*raiz == NULL);
}

int altura_arvore(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return 0;

    int alt_esq = altura_arvore(&((*raiz)->esquerda));
    int alt_dir = altura_arvore(&((*raiz)->direita));

    return (alt_esq > alt_dir) ? (alt_esq + 1) : (alt_dir + 1);
}

int total_nos(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return 0;

    int total_esq = total_nos(&((*raiz)->esquerda));
    int total_dir = total_nos(&((*raiz)->direita));

    return (total_esq + total_dir + 1);
}

void imprime_pre_ordem(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return;

    printf("%d ", (*raiz)->chave);
    imprime_pre_ordem(&((*raiz)->esquerda));
    imprime_pre_ordem(&((*raiz)->direita));
}

void imprime_em_ordem(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return;

    imprime_em_ordem(&((*raiz)->esquerda));
    printf("%d ", (*raiz)->chave);
    imprime_em_ordem(&((*raiz)->direita));
}

void imprime_pos_ordem(Arvore *raiz)
{
    if (raiz == NULL || *raiz == NULL)
        return;

    imprime_pos_ordem(&((*raiz)->esquerda));
    imprime_pos_ordem(&((*raiz)->direita));
    printf("%d ", (*raiz)->chave);
}

int insere_no(Arvore *raiz, int valor)
{
    if (raiz == NULL)
        return 0;

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
        return 0;

    novo_no->chave = valor;
    novo_no->direita = NULL;
    novo_no->esquerda = NULL;

    if (*raiz == NULL)
    {
        *raiz = novo_no;
    }
    else
    {
        No *atual = *raiz;
        No *anterior = NULL;

        while (atual != NULL)
        {
            anterior = atual;
            if (valor == atual->chave)
            {
                free(novo_no);
                return 0;
            }
            if (valor > atual->chave)
            {
                atual = atual->direita;
            }
            else
            {
                atual = atual->esquerda;
            }
        }
        if (valor > anterior->chave)
        {
            anterior->direita = novo_no;
        }
        else
        {
            anterior->esquerda = novo_no;
        }
    }
    return 1;
}

int remove_no(Arvore *raiz, int valor)
{
    if (raiz == NULL)
        return 0;

    No *anterior = NULL;
    No *atual = *raiz;

    while (atual != NULL)
    {
        if (valor == atual->chave)
        {
            if (atual == *raiz)
            {
                *raiz = remove_atual(atual);
            }
            else
            {
                if (anterior->direita == atual)
                {
                    anterior->direita = remove_atual(atual);
                }
                else
                {
                    anterior->esquerda = remove_atual(atual);
                }
            }
            return 1;
        }
        anterior = atual;
        if (valor > atual->chave)
        {
            atual = atual->direita;
        }
        else
        {
            atual = atual->esquerda;
        }
    }
    return 0;
}

int busca_no(Arvore *raiz, int valor)
{
    if (raiz == NULL)
        return 0;

    No *atual = *raiz;
    while (atual != NULL)
    {
        if (valor == atual->chave)
        {
            return 1;
        }
        if (valor > atual->chave)
        {
            atual = atual->direita;
        }
        else
        {
            atual = atual->esquerda;
        }
    }
    return 0;
}
