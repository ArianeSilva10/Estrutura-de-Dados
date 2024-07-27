#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<string> vec1, vec2, vec3;            // cria um vector vazio

    vec1.push_back("ana maria braga");
    vec1.push_back("lucas");
    vec1.push_back("andressa");

    vec3 = vec2 = vec1;

    vec3[1] = "atilio";
    
    cout << "\nvec1:\n";
    for(unsigned int i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << endl;
    }
    cout << "\nvec2:\n";
    for(unsigned int i = 0; i < vec2.size(); ++i) {
        cout << vec2[i] << endl;
    }
    cout << "\nvec3:\n";
    for(unsigned int i = 0; i < vec3.size(); ++i) {
        cout << vec3[i] << endl;
    }

    if(vec1 == vec2) {
        cout << "vec1 eh igual a vec2\n";
    }
    else {
        cout << "vec1 eh diferente de vec2\n";
    }
}