#include <stdio.h>

int main()
{
    int quantidade;
    scanf("%d", &quantidade);

    int s[quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d", &s[i]);
    }

    int dia, mes;
    scanf("%d %d", &dia, &mes);

    int count = 0;

    for (int i = 0; i <= quantidade - mes; i++)
    {
        int soma = 0;
        for (int j = 0; j < mes; j++)
        {
            soma += s[i + j];
        }
        if (soma == dia)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
