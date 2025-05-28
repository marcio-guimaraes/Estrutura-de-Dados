//Transforma de decimal para binário

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{

    int num;
    printf("Numero em decimal: ");
    scanf("%d", &num);

    Pilha *minha_pilha = new_stack();

    while (num > 0)
    {
        push(minha_pilha, num % 2);
        num /= 2;
    }

    int count = size(minha_pilha);

    for (int i = 0; i < count; i++)
    {
        int output = pop(minha_pilha);
        printf("%d", output);
    }
    printf("\n");

    return 0;
}