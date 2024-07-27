#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> consulta(vector<string> s, vector<string> cons){
    vector<int>res;
    for(string str : cons){
        int cont = 0;
        for(string st : s){
            if(st == str){
                cont ++;
            }
        }
        res.push_back(cont);
    }
    return res;
}

int main(){
    int tam_consulta;
    cin >> tam_consulta;
    vector<string> vet_consulta(tam_consulta);

    for(int i = 0; i < tam_consulta; i++){
        cin >> vet_consulta[i];
    }
    int tam_busca;
    cin >> tam_busca;
    vector<string> vet_busca(tam_busca);

    for(int i = 0; i < tam_busca; i++){
        cin >> vet_busca[i];
    }
    vector<int> novo_vet = consulta(vet_consulta, vet_busca);
    for(unsigned int i = 0; i < novo_vet.size(); i++){
        cout << novo_vet[i] << " ";
    }
    novo_vet.pop_back();
    cout << endl;
}