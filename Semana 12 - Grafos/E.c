#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1005
#define INF 1000000000

typedef struct
{
    int x, y;
} Point;

int tamanho, numAmizades;
char grid[MAX][MAX];
int distMonstros[MAX][MAX];
int distA[MAX][MAX];
Point queue[MAX * MAX];
int front, rear;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char moves[4] = {'D', 'U', 'R', 'L'};
char path[MAX][MAX];

int valido(int x, int y)
{
    return x >= 0 && x < tamanho && y >= 0 && y < numAmizades && grid[x][y] != '#';
}

void bfsMonstros()
{
    front = rear = 0;
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < numAmizades; j++)
            distMonstros[i][j] = INF;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < numAmizades; j++)
            if (grid[i][j] == 'M')
            {
                distMonstros[i][j] = 0;
                queue[rear++] = (Point){i, j};
            }

    while (front < rear)
    {
        Point p = queue[front++];
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = p.x + dx[dir];
            int ny = p.y + dy[dir];
            if (valido(nx, ny) && distMonstros[nx][ny] == INF)
            {
                distMonstros[nx][ny] = distMonstros[p.x][p.y] + 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }
}

int bfsA(int startX, int startY)
{
    front = rear = 0;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < numAmizades; j++)
        {
            distA[i][j] = INF;
            path[i][j] = 0;
        }

    distA[startX][startY] = 0;
    queue[rear++] = (Point){startX, startY};

    while (front < rear)
    {
        Point p = queue[front++];

        if (p.x == 0 || p.x == tamanho - 1 || p.y == 0 || p.y == numAmizades - 1)
        {
            int len = distA[p.x][p.y];
            char resultado[len + 1];
            resultado[len] = '\0';

            int cx = p.x, cy = p.y;
            for (int i = len - 1; i >= 0; i--)
            {
                resultado[i] = path[cx][cy];
                switch (resultado[i])
                {
                case 'D':
                    cx -= 1;
                    break;
                case 'U':
                    cx += 1;
                    break;
                case 'R':
                    cy -= 1;
                    break;
                case 'L':
                    cy += 1;
                    break;
                }
            }
            printf("YES\n");
            printf("%d\n", len);
            printf("%s\n", resultado);
            return 1;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = p.x + dx[dir];
            int ny = p.y + dy[dir];

            if (valido(nx, ny))
            {
                if (distA[p.x][p.y] + 1 < distMonstros[nx][ny] && distA[nx][ny] == INF)
                {
                    distA[nx][ny] = distA[p.x][p.y] + 1;
                    path[nx][ny] = moves[dir];
                    queue[rear++] = (Point){nx, ny};
                }
            }
        }
    }

    printf("NO\n");
    return 0;
}

int main()
{
    scanf("%d %d\n", &tamanho, &numAmizades);

    int startX = -1, startY = -1;
    for (int i = 0; i < tamanho; i++)
    {
        fgets(grid[i], numAmizades + 2, stdin);
        for (int j = 0; j < numAmizades; j++)
        {
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    bfsMonstros();

    bfsA(startX, startY);

    return 0;
}
