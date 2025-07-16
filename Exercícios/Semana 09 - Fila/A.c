#include <stdio.h>

int main()
{
    char times[32] = "ABCDEFGHIJKLMNOP";
    char proximaFase[16];

    int idx = 0;
    for (int rodada = 0; rodada < 4; rodada++)
    {
        int jogos = 1 << (3 - rodada);

        for (int i = 0; i < jogos; i++)
        {
            int m, n;
            scanf("%d %d", &m, &n);

            char timeEsquerda = times[i * 2];
            char timeDireita = times[i * 2 + 1];

            proximaFase[i] = m > n ? timeEsquerda : timeDireita;
        }

        for (int i = 0; i < jogos; i++)
        {
            times[i] = proximaFase[i];
        }
    }

    printf("%c\n", times[0]);
    return 0;
}
