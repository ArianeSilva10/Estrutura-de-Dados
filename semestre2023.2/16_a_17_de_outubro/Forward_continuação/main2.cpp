#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
    ForwardList list;

    for(int i = 1; i <= 9; ++i)
        list.insert_after(list.before_begin(), i);

    list.insert_after(list.begin(), {11,22,33});

    for(auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    /*for(int i = 1; i <= 9; ++i)
        list.insert_after(list.before_begin(), i);

    for(auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    list.erase_after(list.before_begin());

    for(auto it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;*/
}