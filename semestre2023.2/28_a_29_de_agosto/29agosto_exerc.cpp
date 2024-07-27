#include <iostream>
#include <string>
using namespace std;

struct usuario{
    string nome;
    string endereco;
    int cpf;
    double salario;
};

int main(){
    const int max = 2;
    usuario vetor[max];

    for(int i = 0; i < max; ++i){
        getline(cin, vetor[i].nome);
        getline(cin, vetor[i].endereco);
        cin.ignore();
        cin >> vetor[i].cpf;
        cin >> vetor[i].salario;
    }
    for(int i = 0; i < max; ++i){
        cout << vetor[i].nome << endl;
        cout << vetor[i].endereco << endl;
        cout << vetor[i].cpf << endl;
        cout << vetor[i].salario;
    }
}
