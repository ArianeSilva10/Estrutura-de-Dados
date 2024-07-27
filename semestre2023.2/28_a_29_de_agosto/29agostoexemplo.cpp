#include <iostream>
using namespace std;
int main(){
    int x{20};
    int *ptr {&x};

    cout << x << endl;//20
    cout << &x << endl; //endereço de x
    cout << ptr << endl; //endereço de x
    cout << *ptr << endl; //20
    *ptr = 666;
    cout << x << endl; //666
}