#include <stdio.h>

int main()
{

    int tamArray, n, quant = 0;

    scanf("%d %d", &tamArray, &n);
    int array[tamArray];

    for (int i = 0; i < tamArray; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < tamArray; i++)
    {
        for (int j = i + 1; j < tamArray; j++)
        {
            if ((array[i] + array[j]) % n == 0)
            {
                quant++;
            }
        }
    }

    printf("%d\n", quant);

    return 0;
}