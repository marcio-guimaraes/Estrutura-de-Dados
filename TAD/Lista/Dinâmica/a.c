#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criaLista()
{
    Lista *novalista = (Lista *)malloc(sizeof(Lista));
    if (novalista != NULL)
    {
        novalista->inicio = NULL;
        novalista->tamanho = 0;
    }

    return novalista;
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
