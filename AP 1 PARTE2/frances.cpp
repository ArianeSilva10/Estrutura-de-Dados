#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    stringstream iss(frase);

    string palavra, res;

    while(iss >> palavra){

        if(palavra[0] != res[res.size() - 2]){
            res = res + palavra + " ";
        }
        else{
            res = res.substr(0,res.size() - 2);
            res = res + palavra;
        }
    }
    cout << res << '\n';
}/*#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;
    getline(cin, texto);

    string resultado;
    char vogalAnterior = ' ';
    bool dentroDeVogais = false;

    for (char c : texto) {
        if (c == ' ') {
            if (!dentroDeVogais && resultado.back() != ' ') {
                resultado += c;
            }
            continue;
        }

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            if (!dentroDeVogais) {
                resultado += c;
                dentroDeVogais = true;
            }
        } else {
            resultado += c;
            dentroDeVogais = false;
        }
    }

    cout << resultado << endl;

    return 0;
}

*/
/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    stringstream iss(frase);

    string palavra, res;

    while(iss >> palavra){
        //int v = 0; // Contador de vogais consecutivas
        bool ad = true; // Flag para indicar se a palavra deve ser adicionada à saída

        for(unsigned int i = 0; i < palavra.size() - 1; ++i){ // -1 para não acessar fora dos limites
            if ((palavra[i] == palavra[i+1]) && // Verifica se duas letras consecutivas são iguais
                (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' ||
                 palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U')) {
                ad = false; // Se sim, não adiciona a palavra à saída
                break; // Sai do loop, pois já determinamos que a palavra não deve ser adicionada
            }
        }

        if(ad){ // Se a palavra deve ser adicionada
            res += palavra; // Adiciona a palavra à saída
        }
    }

    cout << res << '\n';
}

*/

/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    stringstream iss(frase);

    string palavra, res;
    int v;

    while(iss >> palavra){
        v = 0;
        for(unsigned int i = 0; i < frase.size(); ++i){
            if((frase[i] == 'a' && frase[i+1] == 'a') || (frase[i] == 'e' && frase[i+1] == 'e') || (frase[i] == 'i' && frase[i+1] == 'i') || (frase[i] == 'o' && frase[i+1] == 'o') || (frase[i] == 'u' && frase[i+1] == 'u') || (frase[i] == 'A' && frase[i+1] == 'A') || (frase[i] == 'E' && frase[i+1] == 'E') || (frase[i] == 'I' && frase[i+1] == 'I') || (frase[i] == 'O' && frase[i+1] == 'O') || (frase[i] == 'U' && frase[i+1] == 'U')){
                frase.pop_back();
            }
        }
        if(v <= 1){
            res = res + palavra + " ";
        }
        else if(v >= 2){
            res = res + palavra;
        }
    }
   // res.pop_back();
    cout << res << '\n';
}
*/
/*#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string frase;
    getline(cin, frase);
    stringstream iss(frase);

    string palavra, res;
    int v;

    while(iss >> palavra){
        v = 0;
        for(char c : palavra){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                v++;
            }
        }
        if(v <= 1){
            res = res + palavra + " ";
        }
        else if(v >= 2){
            res = res + palavra;
        }
    }
   // res.pop_back();
    cout << res << '\n';
}*/