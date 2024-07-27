#include <iostream>
#include "ForwardList.h"
using namespace std;

// Funcao que recebe uma lista e 
// imprime elementos no terminal
// Complexidade: O(n)
void imprime_lista(ForwardList& lst) {
    auto it = lst.begin(); 
    while(it != lst.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
}

int main() {
    ForwardList lista; // cria lista vazia

    // insere os numeros 9, 8, 7, 6, 5, 4, 3, 2, 1
    for(int i = 1; i <= 9; ++i) {
        lista.push_front(i);
    }

    imprime_lista(lista); // imprime na tela usando iterador
}