#include <iostream>
#include "Queue.h"
using namespace std;

struct Pessoa
{
    string nome;
};

std::ostream& operator<<(std::ostream& obj, Pessoa p){
    obj << p.nome;
    return obj;
}

int main(){
    Queue<Pessoa>filaRU;
    int n;
    cout << "Quantas pessoas? ";
    cin >> n;
    cin.ignore();
    cout << "Digite os nomes: ";
    for(int i = 1; i <= n; ++i){
        string nome;
        getline(cin, nome);
        filaRU.push(Pessoa{nome});
    }
    while (!filaRU.empty())
    {
        cout << filaRU.front().nome << endl;
        filaRU.pop();
    }
    
}