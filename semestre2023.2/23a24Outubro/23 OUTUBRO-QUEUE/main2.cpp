#include <iostream>
#include "Queue.h"
using namespace std;

void intercala(Queue<int>& f1, Queue<int>& f2, Queue<int>& fres)
{
    while(!f1.empty() && !f2.empty()) {
        fres.push(f1.front());
        fres.push(f2.front());
        f1.pop();
        f2.pop();
    }
    while(!f1.empty()) {
        fres.push(f1.front());
        f1.pop();
    }
    while(!f2.empty()) {
        fres.push(f2.front());
        f2.pop();
    }
}

void consome_fila(Queue<int>& fila) {
    while(!fila.empty()) {
        cout << fila.front() << " ";
        fila.pop();
    }
    cout << endl;
}

int main() {
    Queue<int> fila1, fila2, resultado;
    for(int i{1}; i <= 5; ++i) fila1.push(i);
    for(int j{7}; j <= 9; ++j) fila2.push(j);
    intercala(fila1, fila2, resultado);
    consome_fila(resultado);
}