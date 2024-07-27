#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//formatando uma string transformando  cada  ; em  ,

int main(){
    for(int j = 1; j <= 3; ++j){
        string entrada, pedacinho;
        string resultado;
        getline(cin, entrada); // lê a string
        
        //fazendo o mesmo código usando  a stringstream

    istringstream iss(entrada);
    while(getline(iss, pedacinho, ';')){
        resultado = resultado + pedacinho + ',';
    }
    //resultado.pop_back();
    cout << resultado << endl;
    }
//------------------------------------------------------------------------------------------------------------------------
        /*for(unsigned int i = 0; i < entrada.size(); ++i){ // tambem pode ser entrada[i] != '\0'
            if(entrada[i] == ';')
                resultado[i] += ','; // usa concatenação para não dar errado
            else   
                resultado[i] += entrada[i];
        }
        cout << resultado << endl;
    } */
}



/*#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//somar todos os números lidos numa string

int main(){
stringstream iss;
for(int i = 1; i <= 5; ++i){
string input;
std::getline(cin, input);

std::istringstream iss;
iss.str(input);
double token = 0, total = 0;
while(iss >> token){
    total = total + token;
    }
    cout << total << endl;
    iss.clear();
    iss.str("");
    }
}*/