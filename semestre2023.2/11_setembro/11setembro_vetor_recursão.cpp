#include <iostream>
using namespace std;

//recebe um vetor v[0.....n-1]
//com n elementos e 
//retorna o maximo
int maximo(int v[], int n){
    //caso de parada
    if(n == 1){
        return v[0];
    }
    else{
        //caso de geral: v tem pelo menos 2 elementos
        int max = maximo(v, n-1);
        return (max > v[n-1]) ? max : v[n-1];
    }
}
int main(){
    int tamanho;
    cin >> tamanho;
    int *vetor = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        cin >> vetor[i];
    }
    int elemento_maximo = maximo(vetor, tamanho);

    cout << elemento_maximo << endl;
    delete[] vetor;
}