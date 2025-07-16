#include <stdio.h>
#include <math.h>

int acharCombinacao(int x, int n, int vetor[], int indice);

int main()
{
    int x, n, maneiras = 0;
    int potencias[40] = {0};
    scanf("%d", &x);
    scanf("%d", &n);

   
    for (int i = 1; potencias[i - 1] < x; i++)
    {
        potencias[i] = pow(i, n); 
    }

    maneiras = acharCombinacao(x, n, potencias, 1);
    printf("%d\n", maneiras); 

    return 0;
}

int acharCombinacao(int x, int n, int vetor[], int indice)
{
    if (x == 0) return 1; 
    if (x < 0) return 0;  

    int soma = 0;
    for (int i = indice; vetor[i] <= x; i++) 
    {
        soma += acharCombinacao(x - vetor[i], n, vetor, i + 1); 
    }
    return soma;
}
