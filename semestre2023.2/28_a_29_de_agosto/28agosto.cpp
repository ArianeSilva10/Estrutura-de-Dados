#include <iostream>
#include <cmath>
using namespace std;


//area, comprimento da diagonal e perimetro

struct ponto{
    double x;
    double y;
};
//calcula a distancia entre dois pontos
double distancia(ponto p1, ponto p2){
    double dx = ((p1.x - p2.x), 2);
    double dy = ((p1.y - p2.y), 2);
    return sqrt(dx+dy);
}

//um retangulo com quatro vertices e quatro lados
/*P *-----------* S
|              |
|              |
Z *------------*Q

*/
struct retangulo{
    ponto P;
    ponto Q;
    ponto S;
    ponto Z;
};
double altura_retangulo(retangulo r){
    return distancia(r.Q, r.S);
}
double base_retangulo(retangulo r){
    return distancia(r.Z, r.Q);
}
double area_retangulo(retangulo r){
    return base_retangulo(r) * altura_retangulo(r);
}
double perimetro_retangulo(retangulo r){
    return 2*(altura_retangulo(r) + base_retangulo(r));
}
double diagonal_retangulo(retangulo r){
    return sqrt(pow(altura_retangulo(r), 2)
    + pow(base_retangulo(r), 2) );
}

int main(){
    double x, y;
    cout << "Digite as coordenadas do vertice"
            "superior esquerdo";
    cin >> x >> y;
    ponto P{x, y}; //criou o ponto P

    cout << "Digite as coordenadas do vertice"
            "inferior direito";

    cin >> x >> y;
    ponto Q{x, y}; //criou o ponto Q

    ponto S{Q.x, P.y};
    ponto Z{P.x, Q.y};

    retangulo r{P,Q,S,Z};
cout << "area = " ;


}
/*#include <iostream>
#include <cmath>
using namespace std;


area, comprimento da diagonal e perimetro



struct ponto{
    double x;
    double y;
};

um retangulo com quatro vertices e quatro lados
P *-----------* S
|              |
|              |
Z *------------*Q


struct retangulo{
    ponto P;
    ponto Q;
    ponto S;
    ponto Z;
};

retangulo criar_retangulo(ponto P, ponto Q){

}

int main(){
    double x, y;
    cout << "Digite as coordenadas do vertice"
            "superior esquerdo";
    cin >> x >> y;
    ponto P{x, y}; //criou o ponto P

    cout << "Digite as coordenadas do vertice"
            "inferior direito";

    cin >> x >> y;
    ponto Q{x, y}; //criou o ponto Q

    ponto S{Q.x, P.y};
    ponto Z{P.x, Q.y};

    retangulo r{P,Q,S,Z}

}
*/

/*
#include <iostream>
#include <cmath>
using namespace std;


//area, comprimento da diagonal e perimetro

struct ponto{
    double x;
    double y;
};

//um retangulo com quatro vertices e quatro lados
/*P *-----------* S
|              |
|              |
Z *------------*Q


struct retangulo{
    ponto P;
    ponto Q;
    ponto S;
    ponto Z;
};

int main(){
    double x, y;
    cout << "Digite as coordenadas do vertice"
            "superior esquerdo";
    cin >> x >> y;
    ponto P{x, y}; //criou o ponto P

    cout << "Digite as coordenadas do vertice"
            "inferior direito";

    cin >> x >> y;
    ponto Q{x, y}; //criou o ponto Q

    ponto S{Q.x, P.y};
    ponto Z{P.x, Q.y};

    retangulo r{P,Q,S,Z};

}*/




/*#include <iostream>
#include <cmath>
using namespace std;


estrutura para pontos (p,q) raiz((xq - xp)^2 + (yq - yp)^2).



struct ponto{
    double x;
    double y;
};
//calcula a distancia entre dois pontos
double distancia(ponto p1, ponto p2){
    double dx = ((p1.x - p2.x), 2);
    double dy = ((p1.y - p2.y), 2);
    return sqrt(dx+dy);
}
int main(){
    ponto origem {0,0};
    double x, y;
    cin >> x >> y;
    ponto p2{x, y};

    distancia(origem, p2);

    cout << distancia(origem , p2) << endl;
}*/
