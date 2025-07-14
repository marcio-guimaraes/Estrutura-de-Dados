#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 200001
#define MAX_EDGES 400001

int n;
int adj_cabeca[MAX_NODES];
int adj_destino[MAX_EDGES];
int adj_proximo[MAX_EDGES];
int contador_arestas = 0;
int tamanho[MAX_NODES];

void adicionar_aresta(int u, int v) {
    contador_arestas++;
    adj_destino[contador_arestas] = v;
    adj_proximo[contador_arestas] = adj_cabeca[u];
    adj_cabeca[u] = contador_arestas;

    contador_arestas++;
    adj_destino[contador_arestas] = u;
    adj_proximo[contador_arestas] = adj_cabeca[v];
    adj_cabeca[v] = contador_arestas;
}

void dfs_tamanhos(int u, int p) {
    tamanho[u] = 1;
    for (int i = adj_cabeca[u]; i != 0; i = adj_proximo[i]) {
        int v = adj_destino[i];
        if (v != p) {
            dfs_tamanhos(v, u);
            tamanho[u] += tamanho[v];
        }
    }
}

int main() {
    scanf("%d", &n);
    
    if (n == 1) {
        printf("1\n");
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        adj_cabeca[i] = 0;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        adicionar_aresta(a, b);
    }

    dfs_tamanhos(1, 0);

    int no_atual = 1;
    int pai_busca = 0;

    while (1) {
        int proximo_no = -1;
        
        for (int i = adj_cabeca[no_atual]; i != 0; i = adj_proximo[i]) {
            int vizinho = adj_destino[i];
            if (vizinho == pai_busca) continue;

            if (tamanho[vizinho] * 2 > n) {
                proximo_no = vizinho;
                break;
            }
        }

        if (proximo_no != -1) {
            pai_busca = no_atual;
            no_atual = proximo_no;
        } else {
            printf("%d\n", no_atual);
            break;
        }
    }

    return 0;
}