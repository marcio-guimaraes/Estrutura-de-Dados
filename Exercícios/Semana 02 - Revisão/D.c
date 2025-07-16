#include <stdio.h>

int main()
{

    int casos;
    scanf("%d", &casos);

    while (casos--)
    {
        int quantAlunos, minimoAlunos;
        scanf("%d %d", &quantAlunos, &minimoAlunos);

        int chegada, pontuais = 0;

        while (quantAlunos--)
        {
            scanf("%d", &chegada);
            if (chegada <= 0)
            {
                pontuais++;
            }
        }

        if (pontuais >= minimoAlunos)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }

    return 0;
}