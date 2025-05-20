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
    if (novo_elemento)
    {
        novo_elemento->dado = item;
        novo_elemento->prox = l->inicio;
        l->inicio = novo_elemento;
        l->tamanho++;
    }
}

int removeItem(Lista *l, int item)
{
    if (l->inicio == NULL)
    {
        return 0;
    }

    No *atual = l->inicio;
    No *anterior = NULL;
    if (atual->dado == item)
    {
        if (anterior == NULL)
        {
            l->inicio = atual->prox;
            free(atual);
            l->tamanho--;
            return 1;
        }
            while (atual != NULL)
            {
                if (atual->dado == item)
                {
                    anterior->prox = atual->prox;
                    free(atual);
                    l->tamanho--;
                    return 1;
                }
            }
        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

/*int removeItem(Lista *l, int item)
{
    if (l->inicio == NULL)
        return 0;

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->dado == item)
        {
            // Se o item está no início da lista
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

    return 0; // Item não encontrado
}
*/

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