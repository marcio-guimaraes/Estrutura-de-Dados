#include <stdio.h>

int calcula(int pepitas, int valor)
{
    if (pepitas == valor)
    {
        return 1;
    }
    else if (pepitas < valor)
    {
        return 0;
    }
    else if (pepitas % 3 == 0)
    {
        return calcula(pepitas / 3, valor) || calcula((pepitas / 3) * 2, valor);
    }
    else
    {
        return 0;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        if (calcula(n, m))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}