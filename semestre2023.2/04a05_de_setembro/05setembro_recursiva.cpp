#include <iostream>
using namespace std;

//ela recebe um inteiro positivo n
// e retorna o valor da soma dos n
//primeiros intteiros positivos: 1+2 + ... + n
int soma(int n){
    if(n == 1){
        return 1;
    }
    return n + soma(n - 1);
}

int main(){
    cout << soma(3) << endl;
}