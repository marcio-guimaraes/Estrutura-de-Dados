#include <stdio.h>

int main()
{

    int arvoreCord1, arvoreCord2;
    int cordMaca, cordLaranja;
    int countMaca, countLaranja;

    scanf("%d%d", &arvoreCord1, &arvoreCord2);
    scanf("%d%d", &cordMaca, &cordLaranja);
    scanf("%d%d", &countMaca, &countLaranja);

    int aux;
    int quantMaca = 0, quantLaranja = 0;

    for (int i = 0; i < countMaca; i++)
    {
        scanf("%d", &aux);
        if (aux + cordMaca >= arvoreCord1 && aux + cordMaca <= arvoreCord2)
        {
            quantMaca++;
        }
    }

    for (int i = 0; i < countLaranja; i++)
    {
        scanf("%d", &aux);
        if (aux + cordLaranja >= arvoreCord1 && aux + cordLaranja <= arvoreCord2)
        {
            quantLaranja++;
        }
    }

    printf("%d\n", quantMaca);
    printf("%d\n", quantLaranja);

    return 0;
}