#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);

    istringstream iss(frase);
    string palavra, nova_palavra;

    while(iss >> palavra){
        string silaba;
        bool primeira = true; //primeira é a variavel booleana que preciso para procurar a primeira silaba de cada palavra

        for(char c : palavra){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                silaba += c;
            }
            else{
                if(silaba.empty()){ // verifico se a silaba é vazia
                    silaba += c;
                }
                else{
                    if(primeira){
                        if(silaba.size() > 1){
                            nova_palavra += silaba + silaba + silaba + c;
                        }
                        else{
                            nova_palavra += silaba + c;
                        }
                        primeira = false;
                    }
                    else{
                        nova_palavra += silaba + c;
                    }
                    silaba.clear();
                    }
                }
            }
        if(!silaba.empty()){
            if(primeira){
                nova_palavra += silaba + silaba + silaba;
            }
            else{
                nova_palavra += silaba;
            }
        }
        nova_palavra += " ";
        }
        cout << nova_palavra << endl;
    
}