#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    double notas[3];
};

int main() {
    const int MAX = 5;

    // Ler dados de alunos do teclado
    Aluno vetor[MAX];
    for(int i = 0; i < MAX; ++i) {
        cout << "Aluno " << i + 1 << "\n";
        cout << "Digite o nome: ";
        getline(cin, vetor[i].nome);
        cout << "Digite a matricula: ";
        cin >> vetor[i].matricula;
        cout << "Digite as notas separadas por espaco: ";
        cin >> vetor[i].notas[0] 
            >> vetor[i].notas[1] 
            >> vetor[i].notas[2];
        cin.ignore();
    }

    // Mostrar os dados lidos dos alunos
    cout << "\nDados dos alunos:\n";
    for(int i = 0; i < MAX; ++i) {
        cout << vetor[i].nome << ", "
             << vetor[i].matricula << ", "
             << vetor[i].notas[0] << ", "
             << vetor[i].notas[1] << ", "
             << vetor[i].notas[2] << "\n";
    }

    // Calcula quem eh o aluno com maior media
    double media_atual {0.0};
    double maior_media {0.0};
    int indice_melhor_aluno {-1};

    for(int i = 0; i < MAX; ++i) {
        media_atual = (vetor[i].notas[0] + vetor[i].notas[1] + vetor[i].notas[2]) / 3.0;
        if(media_atual > maior_media) {
            maior_media = media_atual;
            indice_melhor_aluno = i;
        }
    }

    cout << "\nAluno com a maior media:\n";
    cout << vetor[indice_melhor_aluno].nome 
         << ", Media: " << media_atual << endl;

}