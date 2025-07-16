#include <stdio.h>

#define MAX_VAGOES 1001

void verificar_permutacao(int total_vagoes, int permutacao_alvo[]) {
    int estacao_pilha[MAX_VAGOES];
    int topo_pilha = -1;
    int proximo_vagao_a_chegar = 1;

    for (int i = 0; i < total_vagoes; i++) {
        int vagao_desejado = permutacao_alvo[i];

        while (proximo_vagao_a_chegar <= total_vagoes && (topo_pilha == -1 || estacao_pilha[topo_pilha] != vagao_desejado)) {
            topo_pilha++;
            estacao_pilha[topo_pilha] = proximo_vagao_a_chegar;
            proximo_vagao_a_chegar++;
        }

        if (topo_pilha > -1 && estacao_pilha[topo_pilha] == vagao_desejado) {
            topo_pilha--;
        } else {
            printf("Nao\n");
            return;
        }
    }

    printf("Sim\n");
}

int main() {
    int total_vagoes, total_permutacoes;
    if (scanf("%d %d", &total_vagoes, &total_permutacoes) != 2) {
        return 1;
    }

    for (int i = 0; i < total_permutacoes; i++) {
        int permutacao_alvo[MAX_VAGOES];
        for (int j = 0; j < total_vagoes; j++) {
            scanf("%d", &permutacao_alvo[j]);
        }
        verificar_permutacao(total_vagoes, permutacao_alvo);
    }

    return 0;
}