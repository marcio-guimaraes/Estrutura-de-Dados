#ifndef COFRE_H
#define COFRE_H

// definicao da struct
typedef struct
{
    int codigo;
    float valor;
} Cofre;

// prototipos das funcoes
void inicializaCofre(Cofre *c, int codigo, float valor);
void mostraCofre(Cofre c);
int verificarCodigo(Cofre c, int tentativa);
void alterarValor(Cofre *c, float novoValor);

#endif
