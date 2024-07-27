#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // abre arquivo para leitura de dados
    ifstream file;
    file.open("arq.txt", std::ios::in);
    if(file.is_open()) {
        cout << "---------------\n";
        cout << "conteudo do arquivo \'arq.txt\':\n";
        int x, y, z;
        while(!file.eof()) {
            file >> x >> y >> z;
            if(file.good()) {
                cout << x << " " << y << " " << z << endl;
            }
        }
        cout << "---------------\n";
    }
    else{
        cout << "nao foi possivel abrir arquivo.\n" << endl;
    }
    file.close();

    // abre arquivo texto para escrita ao final do arquivo
    ofstream fileout;
    fileout.open("arq.txt", std::ios::app);
    int x, y, z;
    cout << "Digite 3 inteiros: ";
    cin >> x >> y >> z;
    if(fileout.is_open()) {
        fileout << x << ' ' << y << ' ' << z << '\n';
        cout << "os 3 inteiros foram escritos ao final do arquivo\n";
    }
    else {
        cout << "nao foi possivel abrir arquivo \'arq.txt\'.\n" << endl;
    }
    fileout.close();
}