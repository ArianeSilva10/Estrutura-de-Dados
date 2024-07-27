#include <iostream>
#include <string>

using namespace std;

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};
void resultado(aluno estud){
    if(estud.nota >= 7){
        cout << estud.nome << " aprovado(a) em " << estud.disciplina << endl;
    }
    else if(estud.nota < 7){
        cout << estud.nome << " reprovado(a) em " << estud.disciplina << endl;
    }
}
int main(){

    aluno estudante;

        getline(cin, estudante.nome);
        cin >> estudante.matricula;
        cin.ignore();
        getline(cin, estudante.disciplina);
        cin >> estudante.nota;
        cin.ignore();

        resultado(estudante);
}
