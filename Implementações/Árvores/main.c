#include <stdio.h>
#include "arvore.h"

int main()
{
    // Criando a árvore
    Arvore *arvore_binaria = cria_arvore();

    // Inserindo alguns nós
    printf("Inserindo nós: 50, 30, 90, 20, 40, 95, 80, 35, 45\n");
    insere_no(arvore_binaria, 50);
    insere_no(arvore_binaria, 30);
    insere_no(arvore_binaria, 90);
    insere_no(arvore_binaria, 20);
    insere_no(arvore_binaria, 40);
    insere_no(arvore_binaria, 95);
    insere_no(arvore_binaria, 80);
    insere_no(arvore_binaria, 35);
    insere_no(arvore_binaria, 45);

    printf("\n--- Travessias ---\n");
    printf("Em Ordem (elementos ordenados): ");
    imprime_em_ordem(arvore_binaria);
    printf("\n");

    printf("Pré-Ordem: ");
    imprime_pre_ordem(arvore_binaria);
    printf("\n");

    printf("Pós-Ordem: ");
    imprime_pos_ordem(arvore_binaria);
    printf("\n\n");

    printf("--- Buscas ---\n");
    printf("Buscando 40: %s\n", busca_no(arvore_binaria, 40) ? "Encontrado!" : "Não encontrado.");
    printf("Buscando 100: %s\n", busca_no(arvore_binaria, 100) ? "Encontrado!" : "Não encontrado.");
    printf("\n");

    printf("--- Remoção ---\n");
    printf("Removendo nó 30...\n");
    remove_no(arvore_binaria, 30);

    printf("Em Ordem (após remoção): ");
    imprime_em_ordem(arvore_binaria);
    printf("\n\n");

    printf("--- Informações da Árvore ---\n");
    printf("Altura da árvore: %d\n", altura_arvore(arvore_binaria));
    printf("Total de nós: %d\n", total_nos(arvore_binaria));
    printf("\n");

    libera_arvore(arvore_binaria);
    printf("Árvore liberada da memória.\n");

    return 0;
}