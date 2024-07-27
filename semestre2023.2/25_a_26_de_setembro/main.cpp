#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector meuvet;

    for(int i{1}; i <= 10000; ++i)
        meuvet.push_back(i);
    
    for(unsigned i{0}; i < meuvet.size(); ++i) {
        cout << meuvet[i] << " ";
    }
    cout << endl;
}