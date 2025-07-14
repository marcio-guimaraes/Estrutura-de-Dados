#include <stdio.h>
#include <stdlib.h>

#define MAX 200005

int tamanho;
int head[MAX];
int proximo[2 * MAX];
int destino[2 * MAX];
int fila[MAX];
int visitado[MAX];
int distancia[MAX];
int total = 0;

void adicionar(int u, int v)
{
    destino[total] = v;
    proximo[total] = head[u];
    head[u] = total++;
}

int bfs(int inicio)
{
    for (int i = 1; i <= tamanho; i++)
        visitado[i] = 0;

    int ini = 0, fim = 0;
    fila[fim++] = inicio;
    visitado[inicio] = 1;
    distancia[inicio] = 0;

    int maisDistante = inicio;

    while (ini < fim)
    {
        int atual = fila[ini++];
        for (int i = head[atual]; i != -1; i = proximo[i])
        {
            int vizinho = destino[i];
            if (!visitado[vizinho])
            {
                visitado[vizinho] = 1;
                distancia[vizinho] = distancia[atual] + 1;
                fila[fim++] = vizinho;

                if (distancia[vizinho] > distancia[maisDistante])
                    maisDistante = vizinho;
            }
        }
    }

    return maisDistante;
}

int main()
{
    scanf("%d", &tamanho);

    for (int i = 1; i <= tamanho; i++)
        head[i] = -1;

    for (int i = 0; i < tamanho - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adicionar(a, b);
        adicionar(b, a);
    }

    int ponto1 = bfs(1);
    int ponto2 = bfs(ponto1);

    printf("%d\n", distancia[ponto2]);

    return 0;
}
