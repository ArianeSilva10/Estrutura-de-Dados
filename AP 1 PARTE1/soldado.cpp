#include <iostream>
int main(){
    using namespace std;
    int matriz[3][3];

    for(int i = 0; i < 3;++i){
        for(int j = 0; j < 3; ++j){
            cin >> matriz[i][j];
        }
    }
    int cont = 0;
    for(int j = 0; j < 3; ++j){
        for(int i = 1; i < 3; ++i){
            if(matriz[i][j] < matriz[i-1][j]){
                cont++;
            }
        }
    }
    cout <<  cont << endl;
}