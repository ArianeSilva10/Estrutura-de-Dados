#include <iostream>
using namespace std;

//recebe um vetor v[0.....n-1]
//com fim - ini + 1 elementos e retorna elemento
// maximo desse vetor nesse intervalo
int maximo(int v[], int ini, int fim){
    //caso de parada
    if(ini == fim){
        return v[ini];
    }
        //caso de geral: v tem pelo menos 2 elementos
        int m = (ini+fim)/2;
        int m1 = maximo(v, ini, m);
        int m2 = maximo(v, m+1, fim);
        return (m1 > m2) ? m1 : m2;
}
int main(){
    int v[] = {12, 3, 4, 6, 1, -9,  89, 564, 34, 21, 98, 77};
    int n = sizeof(v) / sizeof(int);
    cout << maximo(v, 0, n-1) << endl;
}