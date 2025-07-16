#include <stdio.h>

int main()
{

    long int n;
    scanf("%ld", &n);

    int nums[n] = {0};

    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        nums[temp - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            printf("%d", i+ 1);
            return 0;
        }
    }

    return 0;
}