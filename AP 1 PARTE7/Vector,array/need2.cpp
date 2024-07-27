#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, E;
    cin >> N;
    cin >> E;

    
    vector<int> fila_circ(N);
    for (int i = 0; i < N; i++) {
        fila_circ[i] = i + 1;
    }

    int pos_atual = E - 1; 
    
    // Enquanto houver mais de um jogador vivo
    while (fila_circ.size() > 1) {
        
        // jogdores vivos
        cout << "[ ";
        for (int i = 0; i < fila_circ.size(); i++) {
            if (i == pos_atual) {
                cout << fila_circ[i] << ">";
            } else {
                cout << fila_circ[i];
            }
            if (i < fila_circ.size()- 1) {
                cout << " ";
            }
        }
        cout << " ]" << "\n";

        // Matar o jogador à frente e passar a espada
        if(pos_atual >= fila_circ.size()-1){
            fila_circ.erase(fila_circ.begin());
        }else{
            fila_circ.erase(fila_circ.begin() + pos_atual +1 );
        }
        //Atualizar a posição atual
        if(pos_atual>= fila_circ.size()-1){
            pos_atual=0;
        }else{
            pos_atual++;
        }
        
       
    }

    // O jogador restante é o vencedor
    cout << "[ " << fila_circ[0] << "> ]";
    cout << "\n";

    return 0;
}