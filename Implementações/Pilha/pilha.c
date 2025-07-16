#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *new_stack()
{
    Pilha *nova_pilha = (Pilha *)malloc(sizeof(Pilha));
    if (nova_pilha->topo != NULL)
    {
        nova_pilha->topo = NULL;
        nova_pilha->tamanho = 0;
    }

    return nova_pilha;
}

void push(Pilha *p, int val)
{
    No *novo_elemento = (No *)malloc(sizeof(No));
    novo_elemento->val = val;

    novo_elemento->anterior = p->topo;
    p->topo = novo_elemento;
    p->tamanho++;
}

int pop(Pilha *p)
{
    if (p == NULL)
    {
        return -1;
    }

    No *atual = p->topo;
    p->topo = atual->anterior;

    int valor = atual->val;

    p->tamanho--;
    free(atual);
    return valor;
}

int peek(Pilha *p)
{
    if (p == NULL)
    {
        return -1;
    }

    return p->topo->val;
}

int isEmpty(Pilha *p)
{
    return p->tamanho == 0;
}

int size(Pilha *p){
    return p->tamanho;
}