#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};
void maior_nota(aluno a1, aluno a2){
    if(a1.nota > a2.nota){
        cout << a1.nome << ", " << fixed << setprecision(1) << a1.nota << endl;
    }
    else if(a2.nota > a1.nota){
        cout << a2.nome << ", " <<  fixed << setprecision(1) << a2.nota << endl;
    }
    else if(a1.nota == a2.nota){
        cout << a1.nome << " e " << a2.nome << ", " <<  fixed << setprecision(1) << a1.nota << endl;
    }
}
int main(){
    const int max = 2;

    aluno vetor[max];

    for(int i = 0; i < max; i++){
        getline(cin, vetor[i].nome);
        cin >> vetor[i].matricula;
        cin.ignore();
        getline(cin, vetor[i].disciplina);
        cin >> vetor[i].nota;
        cin.ignore();
    }
    for(int i = 0; i < max - 1; i++){
        maior_nota(vetor[i],vetor[i+1]);
    }
}
