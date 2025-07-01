#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int *desejados =(int *) malloc(n * sizeof(int));
    int *apartamentos =(int *) malloc(m * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &desejados[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &apartamentos[i]);

    qsort(desejados, n, sizeof(int), cmp);
    qsort(apartamentos, m, sizeof(int), cmp);

    int i = 0, j = 0, alocados = 0;

    while (i < n && j < m)
    {
        if (abs(desejados[i] - apartamentos[j]) <= k)
        {
            alocados++;
            i++;
            j++;
        }
        else if (apartamentos[j] < desejados[i] - k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    printf("%d\n", alocados);

    free(desejados);
    free(apartamentos);
    return 0;
}
