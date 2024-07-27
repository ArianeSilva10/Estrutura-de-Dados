#include <iostream>
using namespace std;

struct pessoa{
    string nome;
    int idade;
};

int main(){
    pessoa carlos{"Carlos", 22};
    pessoa *ptr = &carlos;

    cout << carlos.nome << endl;

    cout << ptr->nome << endl; // Carlos
    cout << ptr->idade << endl; // 22

    ptr->nome = "Carlitos";
    ptr-> idade = 34;

    cout << ptr->nome<< endl; //Carlitos
    cout << ptr -> idade << endl; //34
}
