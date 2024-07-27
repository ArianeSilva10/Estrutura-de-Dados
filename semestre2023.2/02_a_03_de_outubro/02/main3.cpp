#include <iostream>
#include <vector>
using namespace std;

int main() {
    /**
     * @brief Esse programa mostra como usar
     * iterator para navegar em um vector do C++ 
     */
    vector<int> vec {1,2,3,4,5,6,7};

    // it eh um iterator para o inicio
    // usando while
    auto it = vec.begin(); 
    while(it != vec.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    // usando for
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // usando for-each
    for(auto& elem : vec) {
        cout << elem << " ";
    }
    cout << endl;
}