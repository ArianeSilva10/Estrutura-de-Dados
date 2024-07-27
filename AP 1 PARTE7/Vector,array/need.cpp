#include <iostream>
#include <vector>

using namespace std;

void jogoFilaCircular(int N, int ES){
    vector<bool> fila(N, true); 

    int jogadorComEspada = ES - 1;

    while(true){
        int proximoJogador = (jogadorComEspada + 1) % N;

        // Encontre o próximo jogador vivo na fila.
        while(!fila[proximoJogador]){
            proximoJogador = (proximoJogador + 1) % N;
        }

        // Mata o jogador à frente.
        fila[proximoJogador] = false;

        // Atualiza o índice do jogador com a espada.
        jogadorComEspada = (proximoJogador + 1) % N;

        // Imprime a situação atual da fila.
        cout << "[";
        for (int i = 0; i < N; i++){
            if(fila[i]){
                if(i == jogadorComEspada){
                    cout << " " << i + 1 << ">";
                } 
                else{
                    cout << " " << i + 1;
                }
            }
        }
        cout << " ]" << endl;

        // Verifica se apenas um jogador sobreviveu.
        int jogadoresVivos = 0;
        for(int i = 0; i < N; i++){
            if(fila[i]){
                jogadoresVivos++;
            }
        }
        if(jogadoresVivos == 1){
            break;
        }
    }

    // Encontre o jogador que sobreviveu.
   
}

int main(){
    int N, ES;
    cin >> N >> ES;

    jogoFilaCircular(N, ES);

    return 0;
}
