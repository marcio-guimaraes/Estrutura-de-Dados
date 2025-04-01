#include <stdio.h>

int main()
{

    float count, num;
    int positivos = 0, negativos = 0, zeros = 0;

    scanf("%f", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%f", &num);
        if (num > 0)
        {
            positivos++;
        }
        else if (num < 0)
        {
            negativos++;
        }
        else
        {
            zeros++;
        }
    }

    printf("%.6f\n", (float)positivos / count);
    printf("%.6f\n", (float)negativos / count);
    printf("%.6f\n", (float)zeros / count);

    return 0;
}