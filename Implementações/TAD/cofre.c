#include <stdio.h>
#include "cofre.h"

void inicializaCofre(Cofre *c, int codigo, float valor)
{
    c->codigo = codigo;
    c->valor = valor;
}

void mostraCofre(Cofre c)
{
    printf("Codigo: %d | Valor: %.2f\n", c.codigo, c.valor);
}

int verificarCodigo(Cofre c, int tentativa)
{
    return tentativa == c.codigo;
}

void alterarValor(Cofre *c, float novoValor)
{
    int tentativa;
    printf("Codigo: ");
    scanf("%d", &tentativa);

    if (tentativa == c->codigo)
    {
        c->valor = novoValor;
        printf("Valor alterado!\n");
    }
    else
    {
        printf("Codigo incorreto. Nao foi possivel alterar o valor.\n");
    }
}
