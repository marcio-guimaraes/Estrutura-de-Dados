#include <stdio.h>

int buscaPrimeiraOcorrencia(int array[], int n, int chave);
int buscaUltimaOcorrencia(int array[], int n, int chave);

int main()
{
    int quant;
    scanf("%d", &quant);
    int numeros[quant];

    for (int i = 0; i < quant; i++)
    {
        scanf("%d", &numeros[i]);
    }

    int chave;
    scanf("%d", &chave);

    int primeira = buscaPrimeiraOcorrencia(numeros, quant, chave);
    int ultima = buscaUltimaOcorrencia(numeros, quant, chave);

    if (primeira == -1)
    {
        printf("-1 -1 0\n");
    }
    else
    {
        printf("%d %d %d\n", primeira, ultima, ultima - primeira + 1);
    }

    return 0;
}

int buscaPrimeiraOcorrencia(int arr[], int n, int chave)
{
    int esquerda = 0, direita = n - 1, resultado = -1;
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;
        if (arr[meio] == chave)
        {
            resultado = meio;
            direita = meio - 1;
        }
        else if (arr[meio] < chave)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    return resultado;
}

int buscaUltimaOcorrencia(int arr[], int n, int chave)
{
    int esquerda = 0, direita = n - 1, resultado = -1;
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;
        if (arr[meio] == chave)
        {
            resultado = meio;
            esquerda = meio + 1;
        }
        else if (arr[meio] < chave)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    return resultado;
}