#include <stdio.h>
#define INFINITO 1000000000

int minimo(int a, int b)
{
    return a < b ? a : b;
}

int buscamoedas(int valorDesejado, int *moedas, int quantidadeMoedas, int *memorizado)
{
    if (valorDesejado == 0)
        return 0;
    if (valorDesejado < 0)
        return INFINITO;

    if (memorizado[valorDesejado] != -1)
        return memorizado[valorDesejado];

    int menorQuantidade = INFINITO;

    for (int i = 0; i < quantidadeMoedas; i++)
    {
        menorQuantidade = minimo(menorQuantidade,
                                 buscamoedas(valorDesejado - moedas[i], moedas, quantidadeMoedas, memorizado) + 1);
    }

    return memorizado[valorDesejado] = menorQuantidade;
}

int main()
{
    int quantidade, desejado;
    scanf("%d %d", &quantidade, &desejado);

    int moedas[quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d", &moedas[i]);
    }

    int memorizado[desejado + 1];
    for (int i = 0; i <= desejado; i++)
    {
        memorizado[i] = -1;
    }

    int resultado = buscamoedas(desejado, moedas, quantidade, memorizado);

    if (resultado == INFINITO)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", resultado);
    }

    return 0;
}
