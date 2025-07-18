#include <stdio.h>

#define MAX 200005

int tamanho;
int qtdSubordinados[MAX];
int listaAdj[MAX];
int proximo[MAX];
int head[MAX];
int total = 0;

void adicionar(int chefe, int funcionario)
{
    listaAdj[total] = funcionario;
    proximo[total] = head[chefe];
    head[chefe] = total++;
}

int dfs(int funcionario)
{
    int totalSub = 0;
    for (int i = head[funcionario]; i != -1; i = proximo[i])
    {
        int sub = listaAdj[i];
        totalSub += dfs(sub) + 1;
    }
    qtdSubordinados[funcionario] = totalSub;
    return totalSub;
}

int main()
{
    scanf("%d", &tamanho);

    for (int i = 1; i <= tamanho; i++)
        head[i] = -1;

    for (int i = 2; i <= tamanho; i++)
    {
        int chefe;
        scanf("%d", &chefe);
        adicionar(chefe, i);
    }

    dfs(1);

    for (int i = 1; i <= tamanho; i++)
    {
        printf("%d ", qtdSubordinados[i]);
    }
    printf("\n");

    return 0;
}
