#include <stdio.h>

int main()
{

    char entrada[9];
    int hora;

    scanf("%d%s", &hora, entrada);

    if (entrada[6] == 'A')
    {
        entrada[6] = '\0';
        if (hora == 12)
        {
            hora = 0;
        }
    }
    else
    {
        if (hora != 12)
        {
            hora += 12;
        }
        entrada[6] = '\0';
    }

    printf("%.2d%s\n", hora, entrada);

    return 0;
}