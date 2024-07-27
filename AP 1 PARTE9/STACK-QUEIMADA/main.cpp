#include <iostream>
#include "Stack.h"
#include <vector>
#include <queue>
using namespace std;

void tocar_fogo(int nl, int nc,string *matriz, int linha, int coluna){
    if (linha < 0 || linha >= nl || coluna < 0 || coluna >= nc || matriz[linha][coluna] != '#')
    {
        return;
    }
    matriz[linha][coluna] = 'o';
    Stack<char> PilhaQueimada;
    PilhaQueimada.push(matriz[linha][coluna]);
    while (!PilhaQueimada.empty())
    {
        queue<char> listaVizinhos;
        if (matriz[linha - 1][coluna] != 'o' || matriz[linha + 1][coluna] != 'o' || matriz[linha][coluna - 1] != 'o' || matriz[linha][coluna + 1] != 'o')
        {
                    
        listaVizinhos.push(matriz[linha - 1][coluna]);
        listaVizinhos.push(matriz[linha + 1][coluna]);
        listaVizinhos.push(matriz[linha][coluna - 1]);
        listaVizinhos.push(matriz[linha][coluna + 1]);
        }

        if (listaVizinhos.empty())
        {
            PilhaQueimada.pop();
        }
        else
        {
            matriz[linha - 1][coluna] = 'o';
            PilhaQueimada.push(matriz[linha - 1][coluna]);
            matriz[linha + 1][coluna] = 'o';
            PilhaQueimada.push(matriz[linha + 1][coluna]);
            matriz[linha][coluna - 1] = 'o';
            PilhaQueimada.push(matriz[linha][coluna - 1]);
            matriz[linha][coluna + 1] = 'o';
            PilhaQueimada.push(matriz[linha][coluna + 1]);
            }
    }
    
    
}

int main()
{
    int l,c,linha,coluna;
    
    cin >> l >> c >> linha >> coluna;
    string *matriz = new string[l];
    for (int i = 0; i < l; i++)
    {
        string line;
        getchar();
        getline(cin, line);
        matriz[i] = line;
    }
    tocar_fogo(l, c, matriz, linha, coluna);
    for (int i = 0; i < l; i++)
    {
        cout << matriz[i] << "\n";
    } 
    delete[] matriz;
}