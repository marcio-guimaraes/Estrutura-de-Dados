#include <stdio.h>

#define TAM 6

int main()
{

    int matriz[TAM][TAM];
    int soma, maior;

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < TAM - 2; i++)
    {
        for (int j = 0; j < TAM - 2; j++)
        {
            soma = matriz[i][j] + matriz[i][j + 1] + matriz[i][j + 2] + matriz[i + 1][j + 1] + matriz[i + 2][j] + matriz[i + 2][j + 1] + matriz[i + 2][j + 2];
            if (soma > maior || (j == 0 && i == 0))
            {
                maior = soma;
            }
        }
    }

    printf("%d\n", maior);

    return 0;
}