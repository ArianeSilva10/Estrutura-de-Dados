#include <iostream>
using namespace std;

//calcula se a palavra comecando no indice 'ini'
//e terminando no indice 'fim' eh um palindromo
bool palindromo(string  palavra, int ini, int fim){
    if(ini >= fim){
        return true;
    }
        return palavra[ini] == palavra[fim] && palindromo(palavra, ini + 1, fim - 1);
}
int main(){
    string p {"arara"}, q {"socorro"};
    cout << boolalpha << palindromo(p, 0,p.size() - 1) << endl;
    cout << boolalpha << palindromo(q, 0,q.size() - 1) << endl;

}