#include <iostream>
#include <string>
using namespace std;

//função que imprime a matriz após as queimadas
void show(string *mat, int nl) {
    for(int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}
//função recursiva que ocorre as queimadas da questão
void tocar_fogo(int nl, int nc, string* mat, int l, int c){
    //caso base
    if(l < 0 || l >= nl || c < 0 || c >= nc || mat[l][c] != '#'){
        return;
    }
    mat[l][c] = 'o';
    //caso recursivo
    tocar_fogo(nl, nc, mat, l - 1, c);
    tocar_fogo(nl, nc, mat, l + 1, c);
    tocar_fogo(nl, nc, mat, l, c - 1);
    tocar_fogo(nl, nc, mat, l, c + 1);
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string* mat = new string[nl];
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
}
