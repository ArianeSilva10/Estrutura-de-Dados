#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree<int> tree("8 3 1 # # 6 4 # # 7 # # 10 # 14 13 # # #");
    cout << "size = " << tree.size() << endl;
    cout << "serial: " << tree.serial() << endl;
}