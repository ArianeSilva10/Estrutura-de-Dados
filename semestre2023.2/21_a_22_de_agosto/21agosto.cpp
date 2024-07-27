#include <iostream>
#include <string>
using namespace std;

//strings
int main(){
    int n{};
    cout << "Quantas pessoas voce quer adicionar";
    cin >> n;
    while(n > 0){
        int idade{};
    string nome;
    cout << "Digite seu nome completo: ";
    std::getline(cin, nome);
    cout << "Digite sua idade: ";
    cin >> idade; 
    cout << "nome: " << nome << " , Idade:  " << idade << '\n';
    n--;
    }
}

/*
vetores
int main(){
    int vet[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
   // int tamvet = sizeof(vet)/sizeof(vet[0]);


// for- each
for(int val : vet){
    cout << val << " ";
    //faça
}
}*/