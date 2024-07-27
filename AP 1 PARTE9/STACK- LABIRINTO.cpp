#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Pos{
    int l;
    int c;
};

//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool labirinto(vector<string>& matriz, Pos inicio, Pos fim){
    stack<Pos> pilha;
    vector<vector<bool>> visitados(matriz.size(), vector<bool>(matriz[0].size(), false));
    
    pilha.push(inicio);
    visitados[inicio.l][inicio.c] = true;
    while (!pilha.empty())
    {
        Pos topo = pilha.top();
        pilha.pop();

        if (topo.l == fim.l && topo.c == fim.c)
        {
            return true;
        }
        for (Pos  vizinho : get_vizinhos(topo))
        {
            int x = vizinho.l;
            int y = vizinho.c;

            if (x >= 0 && x < matriz.size() && y >= 0 && y < matriz[0].size() && matriz[x][y] != '#' && !visitados[x][y])
            {
                pilha.push(vizinho);
                visitados[x][y] = true;
                matriz[x][y] = '.';
            }
            
        }
        
    }
    return false;
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;

    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);

    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    if (labirinto(mat, inicio, fim))
    {
        for (const string& linha : mat)
        {
            cout << linha << endl;
        }
        
    }else{
        cout << "Nao ha caminho ate o fim." << endl;
    }
}