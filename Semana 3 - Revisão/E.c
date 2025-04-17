#include <stdio.h>
#include <string.h>

int main()
{
    char entrada[101];
    int nums[100], count = 0;

    scanf("%s", entrada);
    int tam = strlen(entrada);

    for (int i = 0; i < tam; i++)
    {
        if (entrada[i] >= '1' && entrada[i] <= '3')
        {
            nums[count++] = entrada[i] - '0';
        }
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (nums[j] < nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (i > 0)
        {
            printf("+");
        }
        printf("%d", nums[i]);
    }
    printf("\n");

    return 0;
}