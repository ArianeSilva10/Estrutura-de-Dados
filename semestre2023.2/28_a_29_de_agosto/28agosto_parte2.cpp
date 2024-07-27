#include <iostream>
#include <string>
using namespace std;

struct aluno{
    string nome;
    int matricula;
    double notas[3];
};

int main(){
    const int max = 2;
    aluno vetor[max];
        for(int i = 0; i < max;++i){
            cout << "Digite o nome: " << endl;
            getline(cin, vetor[i].nome);
            cout << "digite a matricula: "<< endl;
            cin >> vetor[i].matricula;
            cout << "digite as notas separadas por espaço: " << endl;
            cin >> vetor[i].notas[0]
            >> vetor[i].notas[1]
            >> vetor[i].notas[2];
            cin.ignore();
        }
        for(int i = 0; i < max; ++i){
            cout << vetor[i].nome << " "<< vetor[i].notas[0] << endl;
        }
}
