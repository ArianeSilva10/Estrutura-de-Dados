#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    // fazer
    if(n == 0){
        return 0;
    }
    else if(str[0] == c){
        return 1 + contaCaracteres(str.substr(1), n - 1, c);
    }
    else{
        return contaCaracteres(str.substr(1), n - 1, c);
    }

}

int main() 
{
    string frase;
    char caractere;
    int res;
    getline(cin, frase);
    int n = frase.size();

    cin >> caractere;
   // fazer
    res = contaCaracteres(frase, n,caractere);

    cout << res << endl;
    return 0;
}