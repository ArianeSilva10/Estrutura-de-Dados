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
    int v[] = {12, 3, 4, 6, 1, -9,  89, 564, 34, 21, 98, 77};
    int n = sizeof(v) / sizeof(int);
    cout << maximo(v, n) << endl;
}