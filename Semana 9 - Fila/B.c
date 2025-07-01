#include <stdio.h>

int main()
{
    int casos;
    scanf("%d", &casos);

    while (casos--)
    {
        int estudantes;
        scanf("%d", &estudantes);

        int l[1001], r[1001];

        for (int i = 0; i < estudantes; i++)
        {
            scanf("%d %d", &l[i], &r[i]);
        }

        int tempoAtual = 0;

        for (int i = 0; i < estudantes; i++)
        {
            if (tempoAtual < l[i])
            {
                tempoAtual = l[i];
            }

            if (tempoAtual <= r[i])
            {
                printf("%d ", tempoAtual);
                tempoAtual++;
            }
            else
            {
                printf("0 ");
            }
        }

        printf("\n");
    }

    return 0;
}
