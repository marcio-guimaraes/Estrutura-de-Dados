#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int num_vertices = 5;

    Grafo *g = Cria_Grafo(num_vertices);
    if (g == NULL)
    {
        printf("Erro ao criar o grafo.\n");
        return 1;
    }

    Adiciona_Aresta(g, 1, 2);
    Adiciona_Aresta(g, 1, 3);
    Adiciona_Aresta(g, 2, 4);
    Adiciona_Aresta(g, 3, 5);
    Adiciona_Aresta(g, 4, 5);

    imprime_Grafo(g);

    libera_Grafo(g);

    return 0;
}
