#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using Queue = queue<int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int numAlunos, numAmizades;
    cin >> numAlunos >> numAmizades;

    vvi grafo(numAlunos);
    for (int i = 0; i < numAmizades; i++) {
        int alunoA, alunoB;
        cin >> alunoA >> alunoB;
        alunoA--, alunoB--; 
        grafo[alunoA].push_back(alunoB);
        grafo[alunoB].push_back(alunoA);
    }

    vi equipe(numAlunos, 0); 
    bool possivel = true;

    for (int aluno = 0; aluno < numAlunos; aluno++) {
        if (!equipe[aluno]) {
            Queue fila;
            fila.push(aluno);
            equipe[aluno] = 1;
            while (!fila.empty()) {
                int atual = fila.front();
                int proximaEquipe = equipe[atual] % 2 + 1;
                fila.pop();
                for (int amigo : grafo[atual]) {
                    if (!equipe[amigo]) {
                        fila.push(amigo);
                        equipe[amigo] = proximaEquipe;
                    } else if (equipe[amigo] != proximaEquipe) {
                        possivel = false;
                        break;
                    }
                }
                if (!possivel) break;
            }
        }
        if (!possivel) break;
    }

    if (!possivel) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int aluno = 0; aluno < numAlunos; aluno++)
        cout << equipe[aluno] << " \n"[aluno == numAlunos - 1];
}