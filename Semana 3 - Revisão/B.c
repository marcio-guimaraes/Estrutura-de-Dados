#include <stdio.h>

int main()
{

    int tam, rotacoes;
    scanf("%d %d", &tam, &rotacoes);
    int entrada[tam];
    int saida[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &entrada[i]);
    }

    for (int i = 0; i < tam; i++)
    {
        int aux = i - rotacoes;
        while (aux < 0)
        {
            aux += tam;
        }
        saida[aux] = entrada[i]; 
    }
    
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", saida[i]);
    }
    printf("\n");

    return 0;
}