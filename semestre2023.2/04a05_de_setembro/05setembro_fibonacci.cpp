#include <iostream>
using namespace std;

//calcula o n-esimo numero de fibonacci
long fibo(long n){
    if(n == 0 || n == 1){ //caso  de parada ou caso base
    return n;
    }
    else{ //caso geral: n >= 2
        return fibo(n-1) + fibo(n-2);
    }
}

int main(){
    long n, res;
    cin >> n;
    res = fibo(n);
    cout << res << endl;
}