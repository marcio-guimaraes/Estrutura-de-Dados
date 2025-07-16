#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *Cria_Grafo(int num_vertices)
{
    Grafo *novo_grafo = (Grafo *)malloc(sizeof(Grafo));
    if (novo_grafo == NULL)
        return NULL;

    novo_grafo->grau_maximo = 0;
    novo_grafo->eh_ponderado = 0;
    novo_grafo->num_vertices = num_vertices;

    novo_grafo->arestas = (int **)malloc(sizeof(int *) * num_vertices);
    novo_grafo->pesos = (float **)malloc(sizeof(float *) * num_vertices);
    novo_grafo->grau = (int *)calloc(num_vertices, sizeof(int));

    if (novo_grafo->arestas == NULL || novo_grafo->pesos == NULL || novo_grafo->grau == NULL)
    {
        free(novo_grafo->arestas);
        free(novo_grafo->pesos);
        free(novo_grafo->grau);
        free(novo_grafo);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++)
    {
        novo_grafo->arestas[i] = (int *)calloc(num_vertices, sizeof(int));
        novo_grafo->pesos[i] = (float *)calloc(num_vertices, sizeof(float));

        if (novo_grafo->arestas[i] == NULL || novo_grafo->pesos[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(novo_grafo->arestas[j]);
                free(novo_grafo->pesos[j]);
            }
            free(novo_grafo->arestas);
            free(novo_grafo->pesos);
            free(novo_grafo->grau);
            free(novo_grafo);
            return NULL;
        }
    }

    return novo_grafo;
}

void Adiciona_Aresta(Grafo *meu_grafo, int vertice_1, int vertice_2)
{
    int v1 = vertice_1 - 1;
    int v2 = vertice_2 - 1;

    meu_grafo->arestas[v1][v2] = 1;
    meu_grafo->arestas[v2][v1] = 1;

    meu_grafo->grau[v1]++;
    meu_grafo->grau[v2]++;

    if (meu_grafo->grau[v1] > meu_grafo->grau_maximo)
        meu_grafo->grau_maximo = meu_grafo->grau[v1];
    if (meu_grafo->grau[v2] > meu_grafo->grau_maximo)
        meu_grafo->grau_maximo = meu_grafo->grau[v2];
}

int libera_Grafo(Grafo *meu_grafo)
{
    if (meu_grafo == NULL)
        return 0;

    for (int i = 0; i < meu_grafo->num_vertices; i++)
    {
        free(meu_grafo->arestas[i]);
        free(meu_grafo->pesos[i]);
    }
    free(meu_grafo->arestas);
    free(meu_grafo->pesos);
    free(meu_grafo->grau);
    free(meu_grafo);

    return 1;
}

void imprime_Grafo(Grafo *meu_grafo)
{
    if (meu_grafo == NULL)
    {
        printf("Grafo nulo.\n");
        return;
    }

    printf("Matriz de adjacência:\n");
    for (int i = 0; i < meu_grafo->num_vertices; i++)
    {
        printf("V%d: ", i + 1);
        for (int j = 0; j < meu_grafo->num_vertices; j++)
            printf("%d ", meu_grafo->arestas[i][j]);
        printf("\n");
    }

    printf("\nGrau de cada vértice:\n");
    for (int i = 0; i < meu_grafo->num_vertices; i++)
        printf("V%d: %d\n", i + 1, meu_grafo->grau[i]);

    printf("\nGrau máximo do grafo: %d\n", meu_grafo->grau_maximo);
}
