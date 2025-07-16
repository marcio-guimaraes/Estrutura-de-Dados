#include <stdio.h>
#include <stdlib.h>

int main()
{

    int casos;
    int entrada[100] = {0};
    int saida[100] = {0};

    scanf("%d", &casos);

    while (casos--)
    {
        int ehfila = 1, ehpilha = 1;
        int quantidade;
        scanf("%d", &quantidade);
        for (int i = 0; i < quantidade; i++)
        {
            scanf("%d", &entrada[i]);
        }
        for (int i = 0; i < quantidade; i++)
        {
            scanf("%d", &saida[i]);
        }
        
        for (int i = 0; i < quantidade; i++)
        {
            if (entrada[i] != saida[i])
            {
                ehfila = 0;
            }
            if (entrada[i] != saida[quantidade - 1 - i])
            {
                ehpilha = 0;
            }
        }
        

        int soma = ehfila + ehpilha;
        if (soma == 0)
        {
            printf("neither\n");
        }
        else if (soma == 1)
        {
            if (ehfila)
            {
                printf("queue\n");
            }
            else
            {
                printf("stack\n");
            }
        }
        else
        {
            printf("both\n");
        }
    }

    return 0;
}