#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char entrada[100010];

    scanf("%[^\n]", entrada);
    int tam = strlen(entrada);
    int contador = 0;

    for (int i = 0; i < tam; i++)
    {
        if (entrada[i] >= 'A' && entrada[i] <= 'Z')
        {
            contador++;
        }
    }

    printf("%d\n", ++contador);

    return 0;
}
