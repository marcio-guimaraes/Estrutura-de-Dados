#ifndef PILHA_H
#define PILHA_H

typedef struct Node
{
    int val;
    struct Node* anterior;
} No;


typedef struct Stack
{
    int tamanho;
    No *topo;
} Pilha;


Pilha *new_stack();

void push(Pilha *p, int val);

int pop(Pilha *p);

int peek(Pilha *p);

int isEmpty(Pilha *p);

int size(Pilha *p);

#endif