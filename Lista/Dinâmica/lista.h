#ifndef LISTA_H
#define LISTA_H

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct Lista
{
    No *inicio;
    int tamanho;
} Lista;

Lista *criaLista(); 
void add(Lista *l, int item);
int removeItem(Lista *l, int item); 
int search(Lista *l, int item); 
int isEmpty(Lista *l); 
void append(Lista *l, int item);
int indice(Lista *l, int item); 
int insert(Lista *l, int pos, int item);
int insereOrdenado(Lista *l, int item); 
int pop(Lista *l); 
int popPos(Lista *l, int pos);
void imprimeLista(Lista *l);
int liberaLista(Lista *l);

#endif
