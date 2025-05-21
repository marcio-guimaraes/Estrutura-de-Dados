#ifndef FILA_H
#define FILA_H

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct Fila
{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

Fila *Queue();

void enqueue(Fila *f, int item);

int dequeue(Fila *f);

int front(Fila *f);

int isEmpty(Fila *f);

int size(Fila *f);

#endif
