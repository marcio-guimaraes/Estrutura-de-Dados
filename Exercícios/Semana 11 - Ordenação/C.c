#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main()
{
    int n;
    long long x;
    scanf("%d %lld", &n, &x);

    int *p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    qsort(p, n, sizeof(int), cmp);

    int i = 0, j = n - 1;
    int cabines = 0;

    while (i <= j)
    {
        if (i != j && (long long)p[i] + p[j] <= x)
        {
            i++;
            j--;
        }
        else
        {
            j--;
        }
        cabines++;
    }

    printf("%d\n", cabines);

    free(p);
    return 0;
}
