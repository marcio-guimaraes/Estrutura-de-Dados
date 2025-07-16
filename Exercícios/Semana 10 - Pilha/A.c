#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *anterior;
} No;

typedef struct Stack
{
    int tamanho;
    No *topo;
} Pilha;

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

int main()
{
    Pilha *minha_pilha = new_stack();

    int quantidade;
    scanf("%d", &quantidade);

    int num;
    while (quantidade--)
    {
        scanf("%d", &num);

        if (num == 0)
        {
            pop(minha_pilha);
        }
        else
        {
            push(minha_pilha, num);
        }
    }

    int soma = 0;
    No *atual = minha_pilha->topo;
    while (atual != NULL)
    {
        soma += atual->val;
        atual = atual->anterior;
    }

    printf("%d", soma);

    return 0;
}