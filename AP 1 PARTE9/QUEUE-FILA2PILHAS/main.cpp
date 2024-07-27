#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    int q, i;
    cin >> q;
    Queue<int> Fila;
    while (q > 0)
    {
        cin >> i;
        if(i == 1){
            int add;
            cin >> add;
            Fila.push(add);
        }
        else if(i == 2){
            Fila.pop();
        }
        else if(i == 3){
            cout << Fila.front() << endl;
        }
        q--;
    }
    
}