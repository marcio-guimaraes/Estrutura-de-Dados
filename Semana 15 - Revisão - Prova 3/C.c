#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PLANETAS 21

int numeroDePlanetas, numeroDeRotas;
int matrizDeRotas[MAX_PLANETAS][MAX_PLANETAS];
int distancias[MAX_PLANETAS];
int visitados[MAX_PLANETAS];

int encontrarProximoPlaneta() {
    int menorDistancia = INT_MAX;
    int proximoPlaneta = -1;

    for (int i = 1; i <= numeroDePlanetas; i++) {
        if (!visitados[i] && distancias[i] < menorDistancia) {
            menorDistancia = distancias[i];
            proximoPlaneta = i;
        }
    }
    return proximoPlaneta;
}

void dijkstra(int planetaInicial) {
    for (int i = 1; i <= numeroDePlanetas; i++) {
        distancias[i] = INT_MAX;
        visitados[i] = 0;
    }
    distancias[planetaInicial] = 0;

    for (int i = 1; i <= numeroDePlanetas; i++) {
        int planetaAtual = encontrarProximoPlaneta();

        if (planetaAtual == -1) {
            break;
        }

        visitados[planetaAtual] = 1;

        for (int planetaVizinho = 1; planetaVizinho <= numeroDePlanetas; planetaVizinho++) {
            int comprimentoRota = matrizDeRotas[planetaAtual][planetaVizinho];
            
            if (comprimentoRota != INT_MAX && distancias[planetaAtual] + comprimentoRota < distancias[planetaVizinho]) {
                distancias[planetaVizinho] = distancias[planetaAtual] + comprimentoRota;
            }
        }
    }
}

int main() {
    scanf("%d %d", &numeroDePlanetas, &numeroDeRotas);

    for (int i = 1; i <= numeroDePlanetas; i++) {
        for (int j = 1; j <= numeroDePlanetas; j++) {
            matrizDeRotas[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < numeroDeRotas; i++) {
        int origem, destino, comprimento;
        scanf("%d %d %d", &origem, &destino, &comprimento);
        
        if (comprimento < matrizDeRotas[origem][destino]) {
             matrizDeRotas[origem][destino] = comprimento;
        }
    }

    dijkstra(1);

    for (int i = 1; i <= numeroDePlanetas; i++) {
        printf("%d", distancias[i]);
        if (i < numeroDePlanetas) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}