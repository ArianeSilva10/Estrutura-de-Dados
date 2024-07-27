#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> pilha;

    for(int i{1}; i <= 9; ++i) {
        pilha.push(i);
    }

    Stack<int> pilha_copy (pilha);

    while(!pilha_copy.empty()) {
        cout << pilha_copy.top() << " ";
        pilha_copy.pop();
    }
}