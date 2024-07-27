#include <iostream>
using namespace std;

void imprimir_array(int v[], int n){
    for(int i = 0; i < n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    int vetor[10] = {1,2,3,4,5,6,7,8,9,0};
    imprimir_array(vetor,10);

    int *ptr = vetor;

    for(int i = 0; i < 10;++i){
        cout << ptr[i] << " ";
    }
    cout << endl;
}