#include <iostream>
#include <vector>
using namespace std;

int main(){
    int size, e;
    cin >> size >> e;

    vector<int> elementos(size - 1); 
    int pos = e - 1;   
    for(int i = 0; i < size; i++){
        cin >> elementos[i];
    }

    for(int i = 0; i < size; i++){
        elementos[i] = i + 1;
    }
    depois = e - 1;

    for(int i = 0; i < size - 1; i++){
        cout << "[ ";
        for(int j = 0; j <  size; j++){
            if(j != 0){
                if(j == depois){
                    cout << elementos[j] << "> ";
                }
                else{
                    cout << elementos[j] << " ";
                }
            }
        }
        cout << "]/n";
    }

    // matar equivale a fazer
    vivos[pos] = false;
    // o próximo vivo seria uma busca pelo próximo vivo depois de pos
    int prox = procurar_vivo(elementos, size, pos);

    // faça a funcao matar que remove o elemento do vetor
    // perceba que TUDO após pos, vai diminuir em 1
    int elementos[size];
    matar(elementos, size, pos);
    size -= 1;
    pos = pos % size; // se ele era o último agora é o zero
}
