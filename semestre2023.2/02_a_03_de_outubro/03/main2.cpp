#include <iostream>
#include "Vector.h"
using namespace std;

int main(){
    Vector<int>vec;

    for(int i = 1; i <= 9; i++)
        vec.push_back(i);
    
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}