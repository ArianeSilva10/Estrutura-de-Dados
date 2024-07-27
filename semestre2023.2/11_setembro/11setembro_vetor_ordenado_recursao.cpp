#include <iostream>
using namespace std;

/*
Recebe um vetor v[ini....fim] com fim-ini+1 elementos
ordenado em ordem crescente
e recebe um valor
retorna o indice de val se ele estiver no vetor
*/
int busca_binaria(int v[], int ini, int fim, int val){
    if(ini > fim){
        return -1;
    }
    int m = (ini+fim)/2;
    if(v[m] == val)
        return m;
    if(v[m] > val)
        return busca_binaria(v, ini, m -1, val);
    else
        return busca_binaria(v, m+1, fim, val);
}

int main(){
    int v[] = {1, 2 ,3, 5, 7, 88, 99};
    cout << busca_binaria(v, 0, 6, 87) << endl;
}