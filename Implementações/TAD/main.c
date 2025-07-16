#include <stdio.h>
#include "cofre.h"

int main()
{
    Cofre cofrinho;
    int codigo;
    float valor;

    printf("Codigo: ");
    scanf("%d", &codigo);
    printf("Valor: ");
    scanf("%f", &valor);

    inicializaCofre(&cofrinho, codigo, valor);
    mostraCofre(cofrinho);

    int tentativa;
    printf("Qual o codigo: ");
    scanf("%d", &tentativa);

    int resultado = verificarCodigo(cofrinho, tentativa);
    if (resultado == 1)
    {
        printf("Codigo correto\n");
    }
    else
    {
        printf("Codigo incorreto\n");
    }

    float novoValor;
    printf("Novo valor: ");
    scanf("%f", &novoValor);

    alterarValor(&cofrinho, novoValor);

    return 0;
}
