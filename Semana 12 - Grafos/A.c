#include <stdio.h>

int tamanho, numAmizades;
char mapa[1000][1001];
int visitado[1000][1000];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    if (x < 0 || x >= tamanho || y < 0 || y >= numAmizades)
        return;
    if (mapa[x][y] == '#' || visitado[x][y])
        return;

    visitado[x][y] = 1;

    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
}

int main()
{
    scanf("%d %d", &tamanho, &numAmizades);
    for (int i = 0; i < tamanho; i++)
        scanf("%s", mapa[i]);

    int resposta = 0;

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < numAmizades; j++)
        {
            if (mapa[i][j] == '.' && !visitado[i][j])
            {
                dfs(i, j);
                resposta++;
            }
        }
    }

    printf("%d\n", resposta);
    return 0;
}