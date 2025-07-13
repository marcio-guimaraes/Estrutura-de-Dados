#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct
{
    int x, y;
} Ponto;

int n, m;
char mapa[MAX][MAX + 1];
int visitado[MAX][MAX];
Ponto pai[MAX][MAX];
char direcao[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char moveChar[] = {'U', 'D', 'L', 'R'};

Ponto fila[MAX * MAX];
int frente = 0, tras = 0;

void bfs(int sx, int sy)
{
    visitado[sx][sy] = 1;
    fila[tras++] = (Ponto){sx, sy};

    while (frente < tras)
    {
        Ponto atual = fila[frente++];
        for (int i = 0; i < 4; i++)
        {
            int nx = atual.x + dx[i];
            int ny = atual.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visitado[nx][ny] && mapa[nx][ny] != '#')
            {
                visitado[nx][ny] = 1;
                pai[nx][ny] = atual;
                direcao[nx][ny] = moveChar[i];
                fila[tras++] = (Ponto){nx, ny};
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int ax, ay, bx, by;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", mapa[i]);
        for (int j = 0; j < m; j++)
        {
            if (mapa[i][j] == 'A')
            {
                ax = i;
                ay = j;
            }
            if (mapa[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    bfs(ax, ay);

    if (!visitado[bx][by])
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    char caminho[MAX * MAX];
    int len = 0;
    int x = bx, y = by;

    while (x != ax || y != ay)
    {
        caminho[len++] = direcao[x][y];
        Ponto p = pai[x][y];
        x = p.x;
        y = p.y;
    }

    printf("%d\n", len);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", caminho[i]);
    printf("\n");

    return 0;
}