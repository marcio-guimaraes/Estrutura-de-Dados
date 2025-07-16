#include <stdio.h>

#define MAX 100001

int main()
{
    int n;
    scanf("%d", &n);

    int seq[MAX];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &seq[i]);
    }

    int freq[MAX] = {0};
    int inicio = 0, fim = 0, maxTam = 0;

    while (fim < n)
    {
        while (freq[seq[fim]])
        {
            freq[seq[inicio]]--;
            inicio++;
        }

        freq[seq[fim]]++;
        int tamAtual = fim - inicio + 1;
        if (tamAtual > maxTam)
        {
            maxTam = tamAtual;
        }

        fim++;
    }

    printf("%d\n", maxTam);
    return 0;
}
