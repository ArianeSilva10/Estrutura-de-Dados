#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);

    istringstream iss(frase);

    bool lexi = true;
    string palavra, ante;

    while(iss >> palavra){
        if(palavra < ante){
            lexi = false;
            break;
        }
    ante = palavra;
    }
    if(lexi){
        cout << "sim\n";
    }
    else{
        cout << "nao\n";
    }

    return 0;
}