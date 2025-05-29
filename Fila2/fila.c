#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *Queue()
{
    Fila *nova_fila = (Fila *)malloc(sizeof(Fila));
    if (nova_fila)
    {
        nova_fila->fim = NULL;
        nova_fila->inicio = NULL;
        nova_fila->tamanho = 0;
    }

    return nova_fila;
}

void enqueue(Fila *f, int item)
{
    No *novo_elemento = (No *)malloc(sizeof(No));

    if (novo_elemento)
    {
        if (f->fim == NULL)
        {
            f->fim = novo_elemento;
            f->inicio = novo_elemento;
        } 
    }
}