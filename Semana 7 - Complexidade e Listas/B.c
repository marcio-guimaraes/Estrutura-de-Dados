#include <stdio.h>
#include <string.h>

int main()
{
    char entrada[1000000];
    scanf("%s", entrada);

    int tam = strlen(entrada);

    int sequencia = 1, maiorSequencia = 1; 
    for (int i = 0; i < tam; i++)
    {
        if (entrada[i] == entrada[i + 1])
        {
            sequencia++;
        }
        else
        {
            if (sequencia > maiorSequencia)
            {
                maiorSequencia = sequencia;
            }
            sequencia = 1; 
        }
    }

    printf("%d\n", maiorSequencia);

    return 0;
}