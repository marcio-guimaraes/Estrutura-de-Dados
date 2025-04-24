#include <stdio.h>

int coca(int quantidade, int resultado)
{
    if (quantidade < 3)
    {
        return resultado;
    }
    return coca((quantidade / 3) + (quantidade % 3), resultado + (quantidade / 3));
}

int main()
{
    int quantidade;

    while (1)
    {
        scanf("%d", &quantidade);
        if (quantidade == 0)
            break;

        int resultado = coca(quantidade, 0);

        if (quantidade >= 2 && quantidade % 3 == 2)
            resultado++;

        printf("%d\n", resultado);
    }

    return 0;
}
