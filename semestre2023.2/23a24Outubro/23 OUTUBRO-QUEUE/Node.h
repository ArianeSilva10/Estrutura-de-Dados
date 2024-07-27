#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename Type>
struct Node {
    Type data;   // valor a ser guardado
    Node* next;  // ponteiro para o proximo Node

    // Construtor
    Node(const Type& val, Node* nextPtr) {
        data = val;
        next = nextPtr;
    }
    // Destrutor 
    /*~Node() {
        std::cout << "liberou: " << data << '\n';
    }*/
};

#endif