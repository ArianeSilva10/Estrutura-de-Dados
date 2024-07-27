#include <iostream>
using namespace std;
int main(){

    int vetor[10] = {1,2,3,4,5,6,7,8,9,0};

    cout << vetor[0] << endl; // 1
    cout << &vetor[0] << endl; //endereço do primeiro elemento
    cout << vetor << endl; //endereço do primeiro elemento
    cout << *vetor << endl; //1

    int *ptr = vetor;

    cout << ptr << endl; //endereço do primeiro elemento

    *ptr = 50; // muda o primeiro elemento do vetor

    cout << *ptr << endl; //50
    cout << vetor[0] << endl; //50
}