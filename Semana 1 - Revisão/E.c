#include <stdio.h>
#include <stdlib.h>

int main()
{

    int quant;
    scanf("%d", &quant);

    int gatoA, gatoB, ratoC;

    while (quant--)
    {
        scanf("%d%d%d", &gatoA, &gatoB, &ratoC);
    

    if (abs(gatoA - ratoC) < abs(gatoB - ratoC))
    {
        printf("Cat A\n");
    }
    else if (abs(gatoA - ratoC) > abs(gatoB - ratoC))
    {
        printf("Cat B\n");
    }
    else
    {
        printf("Mouse C\n");
    }
}

    return 0;
}