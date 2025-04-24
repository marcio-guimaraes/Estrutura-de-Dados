#include <stdio.h>
#include <string.h>

void calculaSuperDigit(long long soma)
{
    if (soma < 10)
    {
        printf("%lld\n", soma);
        return;
    }

    long long nova_soma = 0;
    while (soma > 0)
    {
        nova_soma += soma % 10;
        soma /= 10;
    }

    calculaSuperDigit(nova_soma);
}

int main()
{
    char num[100001];
    int k;
    long long soma = 0;

    scanf("%s %d", num, &k);

    for (int i = 0; i < strlen(num); i++)
    {
        soma += num[i] - '0';
    }

    soma *= k;

    calculaSuperDigit(soma);

    return 0;
}
