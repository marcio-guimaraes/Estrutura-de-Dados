#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int tempo;
    int tipo;
} Evento;

int cmp(const void *a, const void *b);

int main()
{
    int quant_clientes;
    scanf("%d", &quant_clientes);

    int *chegada = (int *)malloc(quant_clientes * sizeof(int));
    int *saida = (int *)malloc(quant_clientes * sizeof(int));

    for (int i = 0; i < quant_clientes; i++)
    {
        scanf("%d %d", &chegada[i], &saida[i]);
    }

    Evento *eventos = (Evento *)malloc(2 * quant_clientes * sizeof(Evento));

    for (int i = 0; i < quant_clientes; i++)
    {
        eventos[2 * i] = (Evento){chegada[i], +1};
        eventos[2 * i + 1] = (Evento){saida[i], -1};
    }

    qsort(eventos, 2 * quant_clientes, sizeof(Evento), cmp);

    int clientes_atual = 0;
    int max_clientes = 0;

    for (int i = 0; i < 2 * quant_clientes; i++)
    {
        clientes_atual += eventos[i].tipo;
        if (clientes_atual > max_clientes)
        {
            max_clientes = clientes_atual;
        }
    }

    printf("%d\n", max_clientes);

    free(chegada);
    free(saida);
    free(eventos);

    return 0;
}

int cmp(const void *a, const void *b)
{
    Evento *e1 = (Evento *)a;
    Evento *e2 = (Evento *)b;
    return e1->tempo - e2->tempo;
}
