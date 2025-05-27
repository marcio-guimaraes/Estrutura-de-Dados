#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista {
    int dado;
    struct NoLista* proximo;
} No;

No* criarNo(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->proximo = NULL;
    return no;
}

No* inverterLista(No* cabeca) {
    No* anterior = NULL;
    No* atual = cabeca;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;       // salva o próximo nó
        atual->proximo = anterior;      // inverte o ponteiro
        anterior = atual;               // avança o "anterior"
        atual = proximo;                // avança o "atual"
    }

    return anterior;
}

void imprimirLista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d", cabeca->dado);
        if (cabeca->proximo != NULL) printf(" ");
        cabeca = cabeca->proximo;
    }
    printf("\n");
}

int main() {
    int quant_testes;
    scanf("%d", &quant_testes); 

    while (quant_testes--) {
        int quant_elementos;
        scanf("%d", &quant_elementos);

        No* cabeca = NULL;
        No* cauda = NULL;

        for (int i = 0; i < quant_elementos; i++) {
            int valor;
            scanf("%d", &valor);
            No* novo = criarNo(valor);

            if (cabeca == NULL) {
                cabeca = novo;
                cauda = novo;
            } else {
                cauda->proximo = novo;
                cauda = novo;
            }
        }

        No* invertida = inverterLista(cabeca);
        imprimirLista(invertida);
    }

    return 0;
}
