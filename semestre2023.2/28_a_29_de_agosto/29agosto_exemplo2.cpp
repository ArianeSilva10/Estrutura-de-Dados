#include <iostream>
using namespace std;

void troca(int *p1, int *p2){
    int aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main(){
int x = 9;
int y = 10;
cout << "x = " << x << ", y = " << y << endl;

troca(&x, &y); //envia os enderecos das variaveis

cout << "x = " << x << ", y = " << y << endl;
}