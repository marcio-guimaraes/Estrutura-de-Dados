#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int tamanho, numAmizades;
int *adj[MAX];
int grau[MAX];
int vis[MAX];
int pai[MAX];

int cyc[MAX];
int topo = 0;

int dfs(int s, int p)
{
    vis[s] = 1;
    pai[s] = p;

    for (int i = 0; i < grau[s]; i++)
    {
        int v = adj[s][i];
        if (v == p)
            continue;

        cyc[topo++] = v;

        if (!vis[v])
        {
            if (dfs(v, s))
                return 1;
        }
        else
        {
            return 1;
        }
        topo--;
    }
    return 0;
}

int main()
{
    scanf("%d %d", &tamanho, &numAmizades);
    int a, b;
    for (int i = 1; i <= tamanho; i++)
    {
        adj[i] = NULL;
        grau[i] = 0;
        vis[i] = 0;
        pai[i] = -1;
    }

    for (int i = 0; i < numAmizades; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a] = (int *)realloc(adj[a], (grau[a] + 1) * sizeof(int));
        adj[b] = (int *)realloc(adj[b], (grau[b] + 1) * sizeof(int));
        adj[a][grau[a]++] = b;
        adj[b][grau[b]++] = a;
    }

    for (int i = 1; i <= tamanho; i++)
    {
        if (!vis[i])
        {
            topo = 0;
            cyc[topo++] = i;
            if (dfs(i, -1))
            {
                int ciclo_inicial = cyc[topo - 1];
                int ciclo_tam = 1;
                int resultado[MAX];
                resultado[0] = ciclo_inicial;

                for (int j = topo - 2; j >= 0; j--)
                {
                    resultado[ciclo_tam++] = cyc[j];
                    if (cyc[j] == ciclo_inicial)
                        break;
                }

                printf("%d\n", ciclo_tam);
                for (int j = ciclo_tam - 1; j >= 0; j--)
                    printf("%d ", resultado[j]);
                printf("\n");

                for (int k = 1; k <= tamanho; k++)
                {
                    free(adj[k]);
                }
                return 0;
            }
        }
    }

    printf("IMPOSSIBLE\n");

    for (int k = 1; k <= tamanho; k++)
    {
        free(adj[k]);
    }

    return 0;
}
