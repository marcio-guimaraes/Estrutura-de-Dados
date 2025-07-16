#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005
#define MAX_LEN 35

char inicio[MAX_N][MAX_LEN];
char objetivo[MAX_N][MAX_LEN];
char pilha[MAX_N][MAX_LEN];
char resposta[3 * MAX_N];
int topo = -1;
int rpos = 0;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%s", inicio[i]);

    for (int i = 0; i < n; i++)
        scanf("%s", objetivo[i]);

    int ptr = 0;
    int i = 0;

    while (i < n)
    {
        char *corDesejada = objetivo[i];

        if (topo >= 0 && strcmp(pilha[topo], corDesejada) == 0)
        {
            topo--;
            resposta[rpos++] = 'R';
            i++;
            continue;
        }

        int encontrada = 0;
        while (ptr < n)
        {
            if (strcmp(inicio[ptr], corDesejada) == 0)
            {
                resposta[rpos++] = 'M';
                ptr++;
                encontrada = 1;
                i++;
                break;
            }
            else
            {
                strcpy(pilha[++topo], inicio[ptr++]);
                resposta[rpos++] = 'G';
            }
        }

        if (!encontrada)
        {
            if (topo < 0 || strcmp(pilha[topo], corDesejada) != 0)
            {
                printf("Defeito de fabrica!\n");
                return 0;
            }
        }
    }

    resposta[rpos] = '\0';
    printf("%s\n", resposta);
    return 0;
}
