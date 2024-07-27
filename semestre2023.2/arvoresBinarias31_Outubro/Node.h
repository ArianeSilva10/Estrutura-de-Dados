#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
    Type data;
    Node<Type>* left;
    Node<Type>* right;

    Node(const Type& val, Node<Type>* l, Node<Type> *r) 
        : data(val), left(l), right(r)
    {
    }
};

#endif