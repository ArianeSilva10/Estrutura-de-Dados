#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {
    BinaryTree<int> vazia;
    BinaryTree<int> t5(5, vazia, vazia);
    BinaryTree<int> t6(6, vazia, vazia);
    BinaryTree<int> t12(12, vazia, vazia);
    BinaryTree<int> t9(9, t5, t6);
    BinaryTree<int> t10(10, vazia, t12);
    BinaryTree<int> t7(7, t9, t10);

    t7.preOrder(); cout << endl;
    t7.postOrder(); cout << endl;
    t7.inOrder(); cout << endl;

    cout << t7.contains(6) << endl;
    cout << t7.contains(100) << endl;

}