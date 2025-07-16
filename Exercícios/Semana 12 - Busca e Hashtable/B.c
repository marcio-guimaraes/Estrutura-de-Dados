#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra
{
    char texto[20];
    int contagem;
} Palavra;

int compara(const void *a, const void *b)
{
    return strcmp(((Palavra *)a)->texto, ((Palavra *)b)->texto);
}

int buscaBinaria(Palavra arr[], int tamanho, char *chave)
{
    int esq = 0, dir = tamanho - 1;
    while (esq <= dir)
    {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(arr[meio].texto, chave);
        if (cmp == 0)
            return meio;
        else if (cmp < 0)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return -1;
}

void checkMagazine(int m, char magazine[][20], int n, char note[][20])
{
    Palavra palavras[m];

    for (int i = 0; i < m; i++)
    {
        strcpy(palavras[i].texto, magazine[i]);
        palavras[i].contagem = 1;
    }

    qsort(palavras, m, sizeof(Palavra), compara);

    Palavra compactadas[m];
    int total = 0;

    for (int i = 0; i < m; i++)
    {
        if (total == 0 || strcmp(compactadas[total - 1].texto, palavras[i].texto) != 0)
        {
            strcpy(compactadas[total].texto, palavras[i].texto);
            compactadas[total].contagem = 1;
            total++;
        }
        else
        {
            compactadas[total - 1].contagem++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int pos = buscaBinaria(compactadas, total, note[i]);
        if (pos == -1 || compactadas[pos].contagem == 0)
        {
            printf("No\n");
            return;
        }
        compactadas[pos].contagem--;
    }

    printf("Yes\n");
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    char magazine[m][20];
    char note[n][20];

    for (int i = 0; i < m; i++)
    {
        scanf("%s", magazine[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", note[i]);
    }

    checkMagazine(m, magazine, n, note);

    return 0;
}
