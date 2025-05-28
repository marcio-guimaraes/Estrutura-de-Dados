#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criaLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->inicio = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

void add(Lista *l, int item)
{
    No *novo_elemento = (No *)malloc(sizeof(No));
    if (novo_elemento != NULL)
    {
        novo_elemento->dado = item;
        novo_elemento->prox = l->inicio;
        l->inicio = novo_elemento;
        l->tamanho++;
    }
}

int removeItem(Lista *l, int item)
{
    // a lista existe?
    if (l->inicio == NULL)
        return 0;

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL)
    {
        // if atual == item
        if (atual->dado == item)
        {
            // se tá no começo da lista
            if (anterior == NULL)
            {
                l->inicio = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);
            l->tamanho--;
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

// verificar se o item está na lista;
int search(Lista *l, int item)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    No *atual = l->inicio;

    while (atual != NULL)
    {
        if (atual->dado == item)
        {
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

// verifica se a lista está vazia
int isEmpty(Lista *l)
{
    return l->tamanho == 0;
}

// adiciona elemento no final da lista
void append(Lista *l, int item)
{
    No *atual = l->inicio;
    No *novo_elemento = (No *)malloc(sizeof(No));
    novo_elemento->dado = item;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    atual->prox = novo_elemento;
    novo_elemento->prox = NULL;
}

// retorna o primeiro incice em que o item está
int indice(Lista *l, int item)
{
    No *atual = (No *)malloc(sizeof(No));
    int posicao = 0;

    while (atual != NULL)
    {
        if (atual->dado == item)
        {
            return posicao;
        }
        posicao++;
        atual = atual->prox;
    }

    return -1;
}

// insere em uma posicao especifica
int insert(Lista *l, int posicao, int item)
{
    if (l != NULL)
    {
        return 0;
    }

    if (posicao < 0 || posicao > l->tamanho)
    {
        return 0;
    }

    No *novo_elemento = (No *)malloc(sizeof(No));
    No *atual = l->inicio;
    novo_elemento->dado = item;

    if (posicao == 0)
    {
        novo_elemento->prox = l->inicio;
        l->inicio = novo_elemento;
    }
    else
    {
        for (int i = 0; i < posicao; i++)
        {
            atual = atual->prox;
        }
        novo_elemento->prox = atual->prox;
        atual->prox = novo_elemento;
    }
    l->tamanho++;
    return 1;
}

int insereOrdenado(Lista *l, int item)
{
    No *novo_elemento = (No *)malloc(sizeof(No));
    novo_elemento->dado = item;

    if (l->tamanho == 0)
    {
        l->inicio = novo_elemento;
        l->tamanho++;
        return 1;
    }

    No *atual = l->inicio;
    No *proximo = atual->prox;
}

// int remove o item do fim da lista e retorna ele
int pop(Lista *l)
{
    if (l != NULL)
    {
        return -1;
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }

    int valor = atual->dado;

    if (anterior == NULL)
    {
        l->inicio = NULL;
    }
    else
    {
        anterior->prox = NULL;
    }

    free(atual);
    l->tamanho--;
    return valor;
}

//remove o item de uma posição da lista e retorna ele
int popPos(Lista *l, int posicao)
{
    No *atual = l->inicio;
    No *anterior = NULL;
    int pos = 0;

    if (posicao < 0 || posicao >= l->tamanho)
    {
        return 0;
    }

    for (int i = 0; i < pos; i++)
    {
        anterior = atual;
        atual = atual->prox;
    }

    int valor = atual->dado;

    if (anterior == NULL)
    {
        l->inicio = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }

    free(atual);
    l->tamanho--;
    return valor;
}

void imprimeLista(Lista *l)
{
    if (l != NULL)
    {
        No *atual = l->inicio;
        while (atual != NULL)
        {
            printf("%d\n", atual->dado);
            atual = atual->prox;
        }
    }
}

int liberaLista(Lista *l)
{
    if (l != NULL)
    {
        No *atual = l->inicio;
        No *proximo;
        while (atual != NULL)
        {
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }
    free(l);
    return 1;
}