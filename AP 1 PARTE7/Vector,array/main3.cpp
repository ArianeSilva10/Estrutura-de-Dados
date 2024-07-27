#include <iostream>
#include <vector>
using namespace std;

void jogoFilaCircular(int N, int ES){
    vector<int>fila(N);

    int jogadorComEspada = ES - 1;
    for(int i = 0; i < N; i++){
        fila[i] = i+1;
    }

    while(N > 1){
        cout << "[ ";
        for (int i = 0; i < N; i++){
                if(i == jogadorComEspada){
                    cout << " " << fila[i] << "> ";
                } 
                else{
                    cout << fila[i] << " ";
                }
        }
        cout << "]" << endl;
        int proximoJogador = (jogadorComEspada + 1) % N;

        if(jogadorComEspada == N-1){            
            fila.erase(fila.begin() + proximoJogador );
            jogadorComEspada = (jogadorComEspada + 1) % N;
            N--;
        }
        else{
            fila.erase(fila.begin() + proximoJogador);
            N--;
            jogadorComEspada = (jogadorComEspada + 1) % N;
        }
        //N--;

        if(N == 1){
            cout << "[ " << fila[0] << "> ]" << endl;
        }
    }
}
int main(){
    int N, ES;

    cin >> N >> ES;
    jogoFilaCircular(N, ES);
}