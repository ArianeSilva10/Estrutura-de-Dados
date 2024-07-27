#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct alunos{
  int matricula;
  string nome;
  double media;
};

int main(){
    int tamanho, m;
    cin >> tamanho;
   
   alunos *vetor = new alunos[tamanho];

    for(int i = 0; i < tamanho; i++){
        cin >> vetor[i].matricula;
        cin.ignore();
        getline(cin,vetor[i].nome);
        cin >> vetor[i].media;
    }
    cin >> m;
    bool encontrado = false;

    for(int  i = 0; i < tamanho; i++){
        if(vetor[i].matricula == m){
            cout << vetor[i].nome << endl;
            cout << fixed << setprecision(1) << vetor[i].media << endl;
            encontrado = true;
            break;
        }
    }
    if(!encontrado){
        cout << "NAO ENCONTRADA" << endl;
    }
    delete[] vetor;
}
