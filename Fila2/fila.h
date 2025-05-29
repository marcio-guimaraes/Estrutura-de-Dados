#ifndef FILA_H
#define FILA_H

typedef struct Node
{
    int dado;
    struct node *proximo;

} No;

typedef struct Fila
{
    No *fim;
    No *inicio;
    int tamanho;
} Fila;

Fila *Queue();

void enqueue(Fila *f, int item);

int dequeue(Fila *f);

int front(Fila *f);

#endif