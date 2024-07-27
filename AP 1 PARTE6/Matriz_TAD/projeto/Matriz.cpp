// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m n e n col
Matriz::Matriz(int m, int n) {
	lin = m;
    col = n;
    mat = new int*[lin];
    for(int i = 0; i < lin; i++){
        mat[i] = new int[col];
    }
}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {
	for(int i = 0; i < lin; i++){
		delete[] mat[i];
	}
	delete[] mat;
}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {
	return lin;
} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 
	return col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {
	return mat[i][j];
} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {
	mat[i][j] = valor;
}

// Imprimir a matriz 
void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {
	if(lin != B.linhas() || col != B.colunas()){
        return nullptr;
    }
    Matriz* Matriz_C = new Matriz(lin, col);
	for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            Matriz_C->mat[i][j] = mat[i][j] + B.getValor(i, j);
        }
    }
    return Matriz_C;
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B){
    if(col != B.linhas()){
        return nullptr;
    }
    Matriz* C = new Matriz(lin, B.colunas());

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < B.colunas(); j++){
            C->mat[i][j] = 0;
            for(int k = 0; k < col; k++){
                C->mat[i][j] += mat[i][k] * B.getValor(k, j);
            }
        }
    }

    return C;
}