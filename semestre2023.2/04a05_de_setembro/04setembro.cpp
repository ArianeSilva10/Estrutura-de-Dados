#include <iostream>
#include <string>
using namespace std;
struct pessoa{
    string nome;
    int idade;
};
void preenche_array(pessoa *a, int n){
    for(int i = 0; i < n; i++){
    cin.ignore();
    getline(cin, a[i].nome);
    cin >> a[i].idade;
    }
}
void imprime_array(pessoa *a, int n){
    for(int i = 0; i < n;  i ++){
        cout << a[i].nome << endl << a[i].idade << endl; 
    }
}

int main(){
    int tamanho;
    cin >> tamanho;

    pessoa *vetor = new pessoa[tamanho];

    preenche_array(vetor,tamanho);
    imprime_array(vetor,tamanho);
    delete[] vetor;
}