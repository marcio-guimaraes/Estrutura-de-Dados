#include <stdio.h>
#include <string.h>
#include "comprimir.h"
#include "descomprimir.h"

int main() {
    int opcao;
    char entrada[256];
    char saida[256];

    printf("1 - Comprimir arquivo\n");
    printf("2 - Descomprimir arquivo\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();

    printf("Digite o caminho do arquivo de entrada: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';

    printf("Digite o caminho do arquivo de saida: ");
    fgets(saida, sizeof(saida), stdin);
    saida[strcspn(saida, "\n")] = '\0';

    if (opcao == 1) {
        if (comprimirArquivo(entrada, saida) == 0)
            printf("Arquivo comprimido com sucesso.\n");
        else
            printf("Erro na compressao.\n");
    } else if (opcao == 2) {
        if (descomprimirArquivo(entrada, saida) == 0)
            printf("Arquivo descomprimido com sucesso.\n");
        else
            printf("Erro na descompressao.\n");
    } else {
        printf("Opção invalida.\n");
    }

    return 0;
}
