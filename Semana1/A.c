#include <stdio.h>

int main()
{

    int quantidade, soma = 0;
    scanf("%d", &quantidade);

    while (quantidade)
    {
        int num;
        scanf("%d", &num);
        soma += num;
        quantidade--;
    }

    printf("%d\n", soma);

    return 0;
}