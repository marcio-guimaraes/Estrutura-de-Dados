#include <stdio.h>

int main()
{
    long long int quantValores, consultas;
    scanf("%lld %lld", &quantValores, &consultas);

    long long int valores[quantValores];
    long long int prefixo[quantValores + 1];
    prefixo[0] = 0;

    for (long long int i = 0; i < quantValores; i++)
    {
        scanf("%lld", &valores[i]);
        prefixo[i + 1] = prefixo[i] + valores[i];
    }

    while (consultas--)
    {
        long long int a, b;
        scanf("%lld %lld", &a, &b);
        a--;
        b--;
        printf("%lld\n", prefixo[b + 1] - prefixo[a]);
    }

    return 0;
}