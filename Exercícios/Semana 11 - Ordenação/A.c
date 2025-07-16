#include <stdio.h>
#include <stdlib.h>

// Função pro qsort
int compara(const void *a, const void *b)
{
    int valA = *(int *)a;
    int valB = *(int *)b;
    return (valA > valB) - (valA < valB);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *valores = (int *)malloc(n * sizeof(int));
    if (valores == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &valores[i]);
    }

    qsort(valores, n, sizeof(int), compara);

    int distintos = 1;
    for (int i = 1; i < n; i++)
    {
        if (valores[i] != valores[i - 1])
        {
            distintos++;
        }
    }

    printf("%d\n", distintos);

    free(valores);
    return 0;
}
