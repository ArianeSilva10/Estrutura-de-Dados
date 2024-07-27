#include <iostream>
#include <vector>
using namespace std;

void write(vector<int>& vetor, int n){
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
}
void deixaram(vector<int>& pessoas, int n){
    for(int i = 0; i < n; i++){
        cin >> pessoas[i];
    }
}
vector<int>iden(const vector<int>qtd, const vector<int> id){
    vector<int>res;
    for(unsigned int i = 0;  i < qtd.size(); i++){
        bool encontrado = false;
        for(unsigned int j = 0; j < id.size(); j++){
            if(qtd[i] == id[j]){
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            res.push_back(qtd[i]);
        }
    }
    return res;
}

void show(vector<int>& quant){
    for(unsigned int i = 0; i < quant.size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << quant[i];
    }
    cout << endl;
}

int main(){
    int size, quantidade;
    cin >> size;
    vector<int> fila(size);

    write(fila, size);
    cin >> quantidade;

    vector<int> identifica(quantidade);

    deixaram(identifica, quantidade);
    fila = iden(fila, identifica);
    show(fila);
}