#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

int  main(){
    string frase;
    char caractere;

    getline(cin, frase);
    cin >> caractere;

    istringstream iss(frase);
    string palavra,nova_palavra;

    if(caractere == 'M'){
        while(iss >> palavra){
            for(unsigned int i = 0; i < palavra.size(); i++){
                nova_palavra += toupper(palavra[i]);
            }
            nova_palavra += " ";
        }
    }
    else if(caractere == 'm'){
        while(iss >> palavra){
            for(char c : palavra){
                nova_palavra += tolower(c);
            }
            nova_palavra += " ";
        }
    }   
    else if(caractere == 'p'){
        while(iss >> palavra){
            for (unsigned int i = 0; i < palavra.size() + 1; i++){
                if(i == 0 || palavra[i - 1] == ' '){
                    nova_palavra += toupper(palavra[i]);
                }
                else{
                    nova_palavra += palavra[i];
                }
            }
            nova_palavra += " ";
        }
    }
    else if(caractere == 'i'){
        while(iss >> palavra){
            for(char c : palavra){
                if(isupper(c)){
                    nova_palavra += tolower(c);
                }
                else if(islower(c)){
                    nova_palavra += toupper(c);
                }
                else{
                    nova_palavra += c;
                }
            }
            nova_palavra += " ";
        }
    }
    cout << nova_palavra << endl;
}