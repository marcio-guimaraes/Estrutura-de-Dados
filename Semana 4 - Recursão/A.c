#include <stdio.h>

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return mdc(b, a % b);
}

int main()
{
    int testes;
    scanf("%d", &testes);

    while (testes--)
    {
        int x;
        scanf("%d", &x);

        int melhor_y = 1;
        int valor_maximo = mdc(x, 1) + 1;

        for (int y = 2; y < x; y++)
        {
            int g = mdc(x, y);
            int valor = g + y;
            if (valor > valor_maximo)
            {
                valor_maximo = valor;
                melhor_y = y;
            }
        }

        printf("%d\n", melhor_y);
    }

    return 0;
}