#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 1000
#define MAX_A 1000000

int fatorar(int x, int fatores[], int *quantidade)
{
    int original = x;
    *quantidade = 0;
    for (int i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            fatores[(*quantidade)++] = i;
            x /= i;
        }
    }
    if (x > 1)
    {
        fatores[(*quantidade)++] = x;
    }
    return original;
}

int main()
{
    int n;
    scanf("%d", &n);

    int precos[MAX_N];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &precos[i]);
    }

    int melhor_indice = -1;
    int max_ingredientes = -1;
    int menor_preco = MAX_A + 1;

    for (int i = 0; i < n; i++)
    {
        int fatores[20];
        int qtd;

        fatorar(precos[i], fatores, &qtd);

        if (qtd > max_ingredientes || (qtd == max_ingredientes && precos[i] < menor_preco))
        {
            max_ingredientes = qtd;
            menor_preco = precos[i];
            melhor_indice = i;
        }
    }

    int fatores[20];
    int qtd;
    fatorar(precos[melhor_indice], fatores, &qtd);

    for (int i = 0; i < qtd - 1; i++)
    {
        for (int j = 0; j < qtd - 1 - i; j++)
        {
            if (fatores[j] > fatores[j + 1])
            {
                int temp = fatores[j];
                fatores[j] = fatores[j + 1];
                fatores[j + 1] = temp;
            }
        }
    }

    printf("%d\n", precos[melhor_indice]);
    for (int i = 0; i < qtd; i++)
    {
        printf("%d%c", fatores[i], i == qtd - 1 ? '\n' : ' ');
    }

    return 0;
}
