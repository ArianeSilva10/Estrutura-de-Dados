#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    // escrever no final do arquivo 
    string str("222;Carla Saraiva Almeida;21;Quixada\n");
    fstream fileOut;
    fileOut.open("arqui.txt", ios::app);

    if(!fileOut.is_open()){
        cout << "nao foi possivel abrir\n";
        return 0;
    }
    fileOut << str;
    fileOut.close();
}