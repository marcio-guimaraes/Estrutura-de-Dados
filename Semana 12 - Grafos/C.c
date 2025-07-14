#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int tamanho, numAmizades;
int cor[MAX];
int visitado[MAX];
int *adj[MAX] = {NULL};
int grau[MAX];
int fila[MAX * 2];

void adiciona_aresta(int a, int b)
{
    adj[a] = (int *)realloc(adj[a], (grau[a] + 1) * sizeof(int));
    adj[b] = (int *)realloc(adj[b], (grau[b] + 1) * sizeof(int));
    adj[a][grau[a]++] = b;
    adj[b][grau[b]++] = a;
}

int bfs(int inicio)
{
    int ini = 0, fim = 0;
    fila[fim++] = inicio;
    cor[inicio] = 1;
    visitado[inicio] = 1;

    while (ini < fim)
    {
        int atual = fila[ini++];
        for (int i = 0; i < grau[atual]; i++)
        {
            int viz = adj[atual][i];
            if (!visitado[viz])
            {
                cor[viz] = 3 - cor[atual];
                visitado[viz] = 1;
                fila[fim++] = viz;
            }
            else if (cor[viz] == cor[atual])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    scanf("%d %d", &tamanho, &numAmizades);
    int a, b;

    for (int i = 0; i < tamanho; i++)
        adj[i] = NULL;

    for (int i = 0; i < numAmizades; i++)
    {
        scanf("%d %d", &a, &b);
        adiciona_aresta(a, b);
    }

    for (int i = 1; i <= tamanho; i++)
    {
        if (!visitado[i])
        {
            if (!bfs(i))
            {
                printf("IMPOSSÍVEL\n");
                return 0;
            }
        }
    }

    for (int i = 1; i <= tamanho; i++)
        printf("%d ", cor[i]);
    printf("\n");

    return 0;
}
