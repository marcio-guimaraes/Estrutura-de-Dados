#include <stdio.h>
#include <stdlib.h>

#define TAM 200003

typedef struct No
{
    int valor;
    int indice;
    struct No *prox;
} No;

int hash(int chave)
{
    if (chave < 0)
        chave = -chave;
    return chave % TAM;
}

void inserir(No *tabela[], int valor, int indice)
{
    int h = hash(valor);
    No *novo =(No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->indice = indice;
    novo->prox = tabela[h];
    tabela[h] = novo;
}

int buscar(No *tabela[], int valor)
{
    int h = hash(valor);
    No *atual = tabela[h];
    while (atual)
    {
        if (atual->valor == valor)
            return atual->indice;
        atual = atual->prox;
    }
    return -1;
}

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    No *tabela[TAM] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        int complemento = x - a[i];
        int j = buscar(tabela, complemento);
        if (j != -1)
        {
            printf("%d %d\n", j + 1, i + 1);
            return 0;
        }
        inserir(tabela, a[i], i);
    }

    printf("IMPOSSIBLE\n");
    return 0;
}
