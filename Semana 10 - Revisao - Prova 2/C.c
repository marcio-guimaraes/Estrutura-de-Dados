#include <stdio.h>

int main()
{
    int consultas;
    scanf("%d", &consultas);

    int stack[10000] = {0};
    int top = 99;

    int tipo, valor;
    while (consultas--)
    {
        scanf("%d", &tipo);
        if (tipo == 1)
        {
            scanf("%d", &valor);
            stack[++top] = valor;
        }
        else if (tipo == 2)
        {
            printf("%d\n", stack[top--]);
        }
    }

    return 0;
}
