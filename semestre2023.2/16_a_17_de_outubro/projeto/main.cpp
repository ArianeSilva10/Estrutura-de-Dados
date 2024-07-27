#include <iostream>
#include "List.h"
using namespace std;

int main(){
    List lst;

    for(int i = 1;  i <= 10; ++i){
        lst.push_back(i);
    }

    cout << endl;
}