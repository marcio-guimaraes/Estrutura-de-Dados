#include <stdio.h>

int main()
{

    int consultas;
    int queue[100];
    int index_entrada = 0, index_saida = 0;

    int entrada;
    scanf("%d", &consultas);
    while (consultas--)
    {
        scanf("%d", &entrada);
        if (entrada == 1)
        {
            scanf("%d", &queue[index_entrada++]);
        }
        else if (entrada == 2)
        {
            printf("%d\n", queue[index_saida++]);
        }
    }

    return 0;
}