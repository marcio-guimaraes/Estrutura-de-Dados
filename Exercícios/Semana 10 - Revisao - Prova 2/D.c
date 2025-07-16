#include <stdio.h>

#define MAX 10010

int queueR[MAX], queueI[MAX];
int frontR = 0, rearR = 0;
int frontI = 0, rearI = 0;

int main()
{
    int n;
    char s[MAX];
    scanf("%d %s", &n, s);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            queueR[rearR++] = i;
        else
            queueI[rearI++] = i;
    }

    while (frontR < rearR && frontI < rearI)
    {
        int r = queueR[frontR++];
        int i = queueI[frontI++];
        if (r < i)
            queueR[rearR++] = r + n;
        else
            queueI[rearI++] = i + n;
    }

    printf("%s\n", frontR < rearR ? "Republica" : "Imperio");
    return 0;
}
