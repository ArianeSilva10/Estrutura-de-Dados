#include <iostream>
using namespace std;

//função que irá fazer a soma do vetor para formar o triangulo
void soma_de_triangulo(int array[],int n){
    //caso base
    if(n == 1){
        cout << "[" << array[0] << "]" << endl;
        return;
        }
            int *vet2 = new int[n-1];
            for(int i = 0; i < n - 1; i++){
                vet2[i] = array[i] + array[i+1];
            }
            soma_de_triangulo(vet2, n - 1);
            cout << "[";
            for(int i = 0; i < n; i++){
                cout << array[i];
                if(i < n - 1){
                    cout << ", ";
                }
            }
            cout << "]" << endl;
            delete[] vet2;
    }
    

int main(){
    int tamanho;
    cin >> tamanho;

     int *vetor = new int[tamanho];

    for(int i = 0; i < tamanho; i++){
        cin >> vetor[i];
    }
    soma_de_triangulo(vetor, tamanho);

     delete[] vetor;
}