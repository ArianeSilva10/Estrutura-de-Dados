#include <iostream>
using namespace std;
int main()
{
    int n, i;
    //cout << "Digite um numero: " << endl;
    cin >> n;
    int vetor[n];
    for(i = 0; i < n;++i){
        cin >> vetor[i];
    }
    for(i = 0; i < n - 1;++i){
        if(vetor[i] > vetor[i+1]){
            cout << "precisa de ajuste" << endl;
            break;
        }
    }
    if(i == n - 1){
        cout << "ok" << endl;
    }
    return 0;
}