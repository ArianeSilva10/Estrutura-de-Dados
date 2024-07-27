#include <iostream>
#include <sstream>
#include "Stack.h"
using namespace std;

int main(){
    string frase{"AMU MEGASNEM ATERCES"};
    string token;

    stringstream ss{frase};

    while (ss >> token)
    {
        Stack<char> pilha;
        for(char& c: token){
            pilha.push(c);
        }
        while (!pilha.empty())
        {
            cout  << pilha.top();
            pilha.pop();
        }
        cout << " ";
        
    }
    cout << endl;
    
}

