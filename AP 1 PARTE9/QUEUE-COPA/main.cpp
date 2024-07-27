#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    Queue<char> Equipes;
    for (char i = 'A'; i <= 'P'; ++i)
    {
        Equipes.push(i);
    }

    for (int i = 0; i < 15; ++i)
    {
        int MM, NN;
        cin >> MM >> NN;

        if (MM > NN)
        {
            Equipes.push(Equipes.front());
            Equipes.pop();
            Equipes.pop();
        }
        else
        {
            Equipes.pop();
            Equipes.push(Equipes.front());
            Equipes.pop();
        }
        
    }

    cout << Equipes.front() << endl;
}