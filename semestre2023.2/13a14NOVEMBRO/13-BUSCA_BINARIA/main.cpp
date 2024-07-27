#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "bst.h"
using namespace std;

int main() {
    BST t;
    string skeys;
    int k;
    
    cout << "Digite as chaves separadas por espacos: ";
    getline(cin, skeys);
    stringstream ss { skeys };
    
    while(ss >> k) t.add(k);

    t.bshow();

    cout << "contains(23)? " << boolalpha << t.contains(23) << endl;

    //cout << "Menor chave: " << t.minimum() << endl;
    //cout << "Maior chave: " << t.maximum() << endl;
    
}
