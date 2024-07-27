#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "Node.h"

template <typename Type>
class BinaryTree {
private:
    Node<Type>* m_root {}; // ponteiro para a raiz

public:
    // Construtor vazio: cria uma tree vazia
    BinaryTree() = default;

    // Construtor que cria uma nova arvore
    // a partir de outras duas
    BinaryTree(const Type& val, 
               BinaryTree& tleft,
               BinaryTree& tright)
    {
        m_root = new Node<Type>(val, tleft.m_root, tright.m_root);
        tleft.m_root = tright.m_root = nullptr;
    }

    // Funcao publica que imprime as 
    // chaves em pre-ordem
    void preOrder() const {
        preOrder(m_root);
    }
    void postOrder() const {
        postOrder(m_root);
    }
    void inOrder() const {
        inOrder(m_root);
    }

    // Funcao que retorna true se e somente se arvore vazia
    bool empty() const {
        return m_root == nullptr;
    }
    // Retorna true se e somente se contem a chave na tree
    bool contains(const Type& val) const {
        return contains(m_root, val);
    }

private:
    // Funcao recursiva privada que 
    // recebe uma raiz de arvore e um valor 'val' 
    // e retorna true 
    // se e somente se a arvore contem a chave 'val'
    bool contains(Node<Type>* node, const Type& val) const {
        if(node == nullptr) { // Caso de parada: arvore vazia
            return false;
        }
        else { // Caso geral: a arvore tem pelo menos 1 node
            return val == node->data ||
                   contains(node->left, val) ||
                   contains(node->right, val);
        }
    }

    // Funcao privada que imprime em pre-ordem (raiz-esquerda-direita)
    void preOrder(Node<Type> *node) const {
        if(node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    // Funcao privada que imprime em pos-ordem (esquerda-direta-raiz)
    void postOrder(Node<Type> *node) const {
        if(node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
    // Funcao privada que imprime em ordem simetrica (esquerda-raiz-direita)
    void inOrder(Node<Type> *node) const {
        if(node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

};


#endif 