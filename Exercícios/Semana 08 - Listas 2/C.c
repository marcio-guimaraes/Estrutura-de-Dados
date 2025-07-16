#include <stdio.h>
#include <stdlib.h>

int main() {
    int q;
    scanf("%d", &q);

    int *lista = NULL;
    int tamanho = 0;   

    for (int k = 0; k < q; k++) {
        int tipo;
        scanf("%d", &tipo);

        if (tipo == 1) {
            int n;
            scanf("%d", &n);
            lista = realloc(lista, (tamanho + n) * sizeof(int));
            for (int i = 0; i < n; i++) {
                scanf("%d", &lista[tamanho + i]);
            }
            tamanho += n;

        } else if (tipo == 2) {
            int i;
            scanf("%d", &i);
            if (i >= 0 && i < tamanho) {
                for (int j = i; j < tamanho - 1; j++) {
                    lista[j] = lista[j + 1]; 
                }
                tamanho--;
                lista = realloc(lista, tamanho * sizeof(int)); 
            }

        } else if (tipo == 3) {
            for (int i = 0; i < tamanho / 2; i++) {
                int temp = lista[i];
                lista[i] = lista[tamanho - 1 - i];
                lista[tamanho - 1 - i] = temp;
            }
        }
    }

    printf("%d\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    free(lista); 
    return 0;
}
