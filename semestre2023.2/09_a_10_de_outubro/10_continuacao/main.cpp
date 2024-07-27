#include <iostream>
#include "ForwardList.h"
using namespace std;

//função que recebe uma lista e 
// imprime elementos no terminal
//complexidade: O(n)
void imprime_lista(ForwardList& lst){
    auto it = lst.begin();
    while(it != lst.end()){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    ForwardList Lista;

    for(int i = 1; i <= 9; i++){
        Lista.pushfront(i);
    }
    imprime_lista(Lista);
    //Lista.print();
}