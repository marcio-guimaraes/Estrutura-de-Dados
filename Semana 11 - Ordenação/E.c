#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int inicio, fim;
} Filme;

int cmp(const void *a, const void *b)
{
    Filme *f1 = (Filme *)a;
    Filme *f2 = (Filme *)b;
    return f1->fim - f2->fim;
}

int main()
{
    int n;
    scanf("%d", &n);

    Filme *filmes =(Filme *) malloc(n * sizeof(Filme));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &filmes[i].inicio, &filmes[i].fim);
    }

    qsort(filmes, n, sizeof(Filme), cmp);

    int contador = 0;
    int tempo_atual = 0;

    for (int i = 0; i < n; i++)
    {
        if (filmes[i].inicio >= tempo_atual)
        {
            contador++;
            tempo_atual = filmes[i].fim;
        }
    }

    printf("%d\n", contador);

    free(filmes);
    return 0;
}
