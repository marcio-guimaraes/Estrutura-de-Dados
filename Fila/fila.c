#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *Queue()
{
    Fila *novafila = malloc(sizeof(Fila));

    if (novafila != NULL)
    {
        novafila->inicio = NULL;
        novafila->fim = NULL;
        novafila->tamanho = 0;
    }

    return novafila;
}

void enqueue(Fila *f, int item)
{
    No *novo_elemento = malloc(sizeof(No)); 

    if (novo_elemento != NULL)
    {
        novo_elemento->dado = item;
        novo_elemento->prox = NULL;

        if (f->fim == NULL)
        {
            f->inicio = novo_elemento;
            f->fim = novo_elemento;
        }
        else
        {
            f->fim->prox = novo_elemento;
            f->fim = novo_elemento;
        }

        f->tamanho++;
    }
}

int dequeue(Fila *f)
{
    if (f == NULL || f->inicio == NULL)
        return -1;

    No *remover = f->inicio;
    int valor = remover->dado;
    f->inicio = remover->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(remover);
    f->tamanho--;

    return valor;
}

int front(Fila *f)
{
    if (f == NULL || f->inicio == NULL)
        return -1;

    return f->inicio->dado;
}

int isEmpty(Fila *f)
{
    return f->tamanho == 0;
}

int size(Fila *f)
{
    return f ? f->tamanho : 0;
}
