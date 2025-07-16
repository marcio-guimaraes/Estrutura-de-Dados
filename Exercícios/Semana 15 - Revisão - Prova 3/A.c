#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 200005

int casos, tamanho;
char string[MAXN], s[MAXN], r[27];
int presente[26];
char mapa[26];

int comparar(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    scanf("%d", &casos);

    while (casos--)
    {
        scanf("%d", &tamanho);
        scanf("%s", string);

        for (int i = 0; i < 26; i++)
        {
            presente[i] = 0;
            mapa[i] = 0;
        }

        for (int i = 0; i < tamanho; i++)
        {
            presente[string[i] - 'a'] = 1;
        }

        int tamanhoR = 0;
        for (int i = 0; i < 26; i++)
        {
            if (presente[i])
            {
                r[tamanhoR++] = 'a' + i;
            }
        }

        for (int i = 0; i < tamanhoR; i++)
        {
            char c1 = r[i];
            char c2 = r[tamanhoR - 1 - i];
            mapa[c1 - 'a'] = c2;
        }

        for (int i = 0; i < tamanho; i++)
        {
            s[i] = mapa[string[i] - 'a'];
        }
        s[tamanho] = '\0';

        printf("%s\n", s);
    }

    return 0;
}
