#include <stdio.h>
#include <stdbool.h>

#define MAX_MOTORISTAS 10001

typedef struct
{
    int horario_chegada;
    int horario_saida;
} Motorista;

void resolver_caso_teste()
{
    int total_motoristas, capacidade_estacionamento;
    scanf("%d %d", &total_motoristas, &capacidade_estacionamento);

    Motorista cronograma[MAX_MOTORISTAS];
    int ultimo_horario_saida = 0;

    for (int i = 0; i < total_motoristas; i++)
    {
        scanf("%d %d", &cronograma[i].horario_chegada, &cronograma[i].horario_saida);
        if (cronograma[i].horario_saida > ultimo_horario_saida)
        {
            ultimo_horario_saida = cronograma[i].horario_saida;
        }
    }

    int estacionamento_pilha[MAX_MOTORISTAS];
    int topo_pilha = -1;

    int indice_proximo_motorista = 0;
    bool eh_possivel = true;

    for (int tempo_atual = 1; tempo_atual <= ultimo_horario_saida + 1; tempo_atual++)
    {
        while (topo_pilha > -1 && estacionamento_pilha[topo_pilha] == tempo_atual)
        {
            topo_pilha--;
        }

        if (indice_proximo_motorista < total_motoristas && cronograma[indice_proximo_motorista].horario_chegada == tempo_atual)
        {
            if (topo_pilha + 1 >= capacidade_estacionamento)
            {
                eh_possivel = false;
                break;
            }

            int saida_carro_novo = cronograma[indice_proximo_motorista].horario_saida;
            if (topo_pilha > -1 && estacionamento_pilha[topo_pilha] < saida_carro_novo)
            {
                eh_possivel = false;
                break;
            }

            topo_pilha++;
            estacionamento_pilha[topo_pilha] = saida_carro_novo;
            indice_proximo_motorista++;
        }
    }

    if (eh_possivel && topo_pilha == -1)
    {
        printf("Sim\n");
    }
    else
    {
        printf("Nao\n");
    }
}

int main()
{
    int numero_casos_teste;
    scanf("%d", &numero_casos_teste);
    while (numero_casos_teste--)
    {
        resolver_caso_teste();
    }
    return 0;
}