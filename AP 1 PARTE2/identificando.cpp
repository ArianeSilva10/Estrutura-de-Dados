#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(){

    string frase;
    getline(cin, frase);
    string palavra, tipo;
    istringstream iss(frase);

    while(iss >> palavra){
        bool INT = true;
        bool FLOAT = true;

        for(char c : palavra){
            if(!isdigit(c) &&  c != '-' && c != '.'){
                INT = false;
                FLOAT = false;
                break;
            }
            if(c == '.'){
                INT = false;
            }
        }
            if(INT){
                cout << "int";
            }
            else if(FLOAT){
                cout << "float";
            }
            else{
                cout << "str";
            }
            cout << " ";
    }

}