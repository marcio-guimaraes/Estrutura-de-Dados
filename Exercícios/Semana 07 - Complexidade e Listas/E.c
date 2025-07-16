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

No* deletarNo(No* cabeca, int posicao) {
    if (cabeca == NULL) return NULL;

    if (posicao == 0) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        free(temp);
        return cabeca;
    }

    No* atual = cabeca;
    for (int i = 0; i < posicao - 1 && atual->proximo != NULL; i++) {
        atual = atual->proximo;
    }

    if (atual->proximo != NULL) {
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        free(temp);
    }

    return cabeca;
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

    int posicao;
    scanf("%d", &posicao); 

    cabeca = deletarNo(cabeca, posicao);
    imprimirLista(cabeca);

    return 0;
}
