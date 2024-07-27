#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Função para imprimir o vetor original
void array(vector<int> vetor, size_t i) {
    // Caso base
    if (i == vetor.size()) {
        return;
    }
    cout << vetor[i] << " ";
    array(vetor, i + 1);
}

// Função para imprimir o vetor ao contrário
void rvet(vector<int> vetor, int fim) {
    // Caso base
    if (fim < 0) {
        return;
    }
    cout << vetor[fim] << " ";
    rvet(vetor, fim - 1);
}
//Função  que retorna a soma dos elementos do vetor
int sum(vector<int> vetor, int tamanho, int i = 0){
    //caso base
    if(tamanho == i){
        return 0;
    }
    return vetor[i] + sum(vetor, tamanho, i+1);
}
//Função  que retorna a multiplicação dos elementos do vetor
long mult(vector<int> vetor, int tamanho, int i = 0){
    //caso base
    if(tamanho == i){
        return 1;
    }
    return vetor[i] * mult(vetor, tamanho, i+1);
}
//função que retorna o menor elemento do vetor
int min(vector<int> vetor, int ini, int fim){
    //caso base
    if(ini == fim){
        return vetor[ini];
    }
    int m = (ini+fim)/2;
    int m1 = min(vetor, ini, m);
    int m2 = min(vetor, m+1, fim);
    return (m1 < m2) ? m1 : m2;
}
//função que inverte o vetor e o imprime 
void inv(vector<int> &vetor, int ini, int fim) {
    // Caso base
    if (ini >= fim) {
        return;
    }
    int aux = vetor[ini];
    vetor[ini] = vetor[fim];
    vetor[fim] = aux;
    //cout <<  << " ";
    inv(vetor, ini + 1, fim - 1);
}
int main() {

    string entrada;
    getline(cin, entrada);

    stringstream ss(entrada);

    vector<int> vet;

    int valores;
    while (ss >> valores)
        vet.push_back(valores);

    cout << "vet : [ ";
    array(vet, 0);
    cout << "]" << endl;

    cout << "rvet: [ ";
    rvet(vet, vet.size() - 1);
    cout << "]" << endl;

    int soma = sum(vet, vet.size(), 0);
    cout << "sum : " << soma << endl;

    int produto = mult(vet, vet.size(), 0);
    cout << "mult: " << produto << endl;

    int menor_elemento = min(vet, 0, vet.size() - 1);
    cout << "min : " << menor_elemento << endl;

    cout << "inv : [ ";
    inv(vet, 0, vet.size() - 1);
    for(size_t i = 0; i < vet.size(); i++){
        cout << vet[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}
