#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector<string> vec1;

    vec1.push_back("ana maria braga");
    vec1.push_back("lucas");
    vec1.push_back("andressa");
    
    cout << "vec1:\n";
    for(unsigned int i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << endl;
    }

}