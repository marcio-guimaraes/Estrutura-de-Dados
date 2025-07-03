#ifndef GRAFO_H
#define GRAFO_H

typedef struct grafo
{
    int eh_ponderado;
    int grau_maximo;
    int num_vertices;
    int **arestas;
    float **pesos;
    int *grau;
} Grafo;

Grafo *Cria_Grafo(int num_vertices);

void Adiciona_Aresta(Grafo *meu_grafo, int vertice_1, int vertice_2);

int libera_Grafo(Grafo *meu_grafo);

void imprime_Grafo(Grafo *meu_grafo);

#endif
