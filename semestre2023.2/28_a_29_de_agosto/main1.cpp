#include <iostream>
#include <cmath>
using namespace std;

// Um ponto no plano cartesiano eh definido
// pelas suas coordenadas nos eixos X e Y.
struct Ponto {
    double x;
    double y;
};

// Calcula a distancia entre dois pontos
double distancia(Ponto ponto1, Ponto ponto2){
    double dx = pow((ponto1.x - ponto2.x), 2);
    double dy = pow((ponto1.y - ponto2.y), 2);
    return sqrt(dx+dy);
}

// Um retangulo eh um poligono com 
// quatro vertices e quatro lados.
//
//  P *----------* S
//    |          |
//    |          |
//  Z *----------* Q
//
struct Retangulo {
    Ponto P;
    Ponto Q;
    Ponto S;
    Ponto Z;
};

Retangulo criar_retangulo(Ponto P, Ponto Q) {
    Ponto S { Q.x, P.y };
    Ponto Z { P.x, Q.y };
    Retangulo r {P, Q, S, Z};
    return r;
}

// calcula a altura de um Retangulo
double altura_retangulo(Retangulo r) {
    return distancia(r.Q, r.S);
}

// calcula a base de um Retangulo
double base_retangulo(Retangulo r) {
    return distancia(r.Z, r.Q);
}

// calcula a area de um Retangulo
double area_retangulo(Retangulo r) {
    return base_retangulo(r) * altura_retangulo(r);
}

// calcula o perimetro do Retangulo
double perimetro_retangulo(Retangulo r) {
    return 2 * (altura_retangulo(r) + base_retangulo(r));
}

// calcula a diagonal do retangulo
double diagonal_retangulo(Retangulo r) {
    return sqrt( pow(altura_retangulo(r), 2) 
                 + pow(base_retangulo(r), 2)  );
}

int main() {
    double x, y;
    cout << "Digite as coordenadas do vertice "
            "superior esquerdo: ";
    cin >> x >> y;
    Ponto P {x, y}; // criou o ponto P
    
    cout << "Digite as coordenadas do vertice "
            "inferior direito: ";
    cin >> x >> y;
    Ponto Q {x, y}; // criou o ponto Q

    Retangulo novoTriangulo = criar_retangulo(P,Q);

    cout << "Area = " << area_retangulo(novoTriangulo) << '\n';
    cout << "Perimetro = " << perimetro_retangulo(novoTriangulo) << '\n';
    cout << "Diagonal = " << diagonal_retangulo(novoTriangulo) << '\n';

}