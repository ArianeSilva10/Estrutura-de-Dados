#include <iostream>
using namespace std;
int main(){
    
    int matriz[3][3];

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> matriz[i][j];
        }
    }
    int sl1 = matriz[0][0] + matriz[0][1] + matriz[0][2];
    int diag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
    int diag2 = matriz[0][2] + matriz[1][1] + matriz[2][0];

    int coluna = 0, linha = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            linha += matriz[i][j];
            coluna += matriz[j][i];
        }
        if(linha != sl1 || coluna != sl1){
            cout << "não" << endl;
            return 0;
        }
    }
    if(diag1 != sl1 || diag2 != sl1){
        cout << "não" << endl;
        return 0;
    }
    else{
        cout << "sim";
        return 0;
    }
}