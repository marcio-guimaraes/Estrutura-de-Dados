#ifndef ARVORE_H
#define ARVORE_H

typedef struct No
{
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;

typedef No *Arvore;

Arvore *cria_arvore();

void libera_arvore(Arvore *raiz);

int insere_no(Arvore *raiz, int valor);

int remove_no(Arvore *raiz, int valor);

int busca_no(Arvore *raiz, int valor);

int esta_vazia(Arvore *raiz);

int altura_arvore(Arvore *raiz);

int total_nos(Arvore *raiz);

void imprime_pre_ordem(Arvore *raiz);

void imprime_em_ordem(Arvore *raiz);

void imprime_pos_ordem(Arvore *raiz);

#endif
