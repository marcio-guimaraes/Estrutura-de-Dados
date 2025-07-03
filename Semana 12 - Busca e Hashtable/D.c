#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int upperBound(int torres[], int tamanho, int x)
{
    int esq = 0, dir = tamanho;
    while (esq < dir)
    {
        int meio = (esq + dir) / 2;
        if (torres[meio] > x)
            dir = meio;
        else
            esq = meio + 1;
    }
    return esq;
}

int main()
{
    int n;
    scanf("%d", &n);
    int cubos[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &cubos[i]);

    int torres[n], tamanho = 0;

    for (int i = 0; i < n; i++)
    {
        int pos = upperBound(torres, tamanho, cubos[i]);
        if (pos == tamanho)
            torres[tamanho++] = cubos[i];
        else
            torres[pos] = cubos[i];
    }

    printf("%d\n", tamanho);
    return 0;
}
