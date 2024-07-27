#include <iostream>
#include "ForwardList.h"
using namespace std;

int main(){
    ForwardList Lista;

    for(int i = 1; i <= 9; i++){
        Lista.pushfront(i);
    }
    Lista.print();
}