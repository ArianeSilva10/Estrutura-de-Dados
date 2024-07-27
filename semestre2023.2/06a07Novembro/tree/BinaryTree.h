#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <sstream>
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
    // Construtor que cria uma arvore
    // a partir de uma string serial
    BinaryTree(const std::string& str) {
        std::stringstream ss(str);
        m_root = deserialize(ss);
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
    // Funcao publica que libera a 
    // arvore, ou seja, deixa ela vazia.
    void clear() {
        m_root = clear(m_root);
    }
    // Destrutor
    ~BinaryTree() {
        clear();
    }
    // Retorna o numero de nós da arvore
    unsigned size() const {
        return size(m_root);
    }

    BinaryTree(const BinaryTree& t) = delete;
    BinaryTree& operator=(const BinaryTree& t) = delete;

    // Funcao publica que retorna uma string
    // contendo o serial da arvore
    std::string serial() const {
        std::stringstream ss;
        serialize(m_root, ss);
        return ss.str();
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

    // Funcao privada que imprime em pre-ordem
    void preOrder(Node<Type> *node) const {
        if(node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    // Funcao privada que imprime em pos-ordem
    void postOrder(Node<Type> *node) const {
        if(node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
    // Funcao privada que imprime em ordem simetrica
    void inOrder(Node<Type> *node) const {
        if(node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }
    // Funcao recursiva
    // Que recebe uma raiz de árvore e libera
    // todos os nós dessa árvore. Retornando
    // o ponteiro nulo no final
    Node<Type>* clear(Node<Type>* node) {
        if(node == nullptr) {
            return nullptr;
        }
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
        return nullptr;
    }

    // Funcao recursiva que recebe a 
    // raiz de uma arvore T e retorna
    // quantos nós tem nessa árvore
    unsigned size(Node<Type>* node) const {
        if(node == nullptr) {
            return 0;
        }
        else {
            return 1 + size(node->left) 
                     + size(node->right);
        }
    }

    // Funcao recursiva que recebe uma raiz
    // de arvore e uma stringstream e 
    // cria uma versao serial dessa arvore, 
    // que fica armazenada na stringstream.
    void serialize(Node<Type>* node, 
                   std::stringstream& ss) const 
    {
        if(node == nullptr) { // caso de parada
            ss << "# ";
        }
        else { // caso geral
            ss << node->data << " ";
            serialize(node->left, ss);
            serialize(node->right, ss);
        }
    }

    // Funcao recursiva privada que recebe 
    // uma stringstream contendo o serial
    // da árvore e cria a arvore seguindo
    // um percurso em pre-ordem.
    Node<Type>* deserialize(std::stringstream& ss) {
        std::string valor;
        ss >> valor;
        if(valor == "#") { // arvore vazia
            return nullptr;
        }
        else { // arvore nao vazia
            std::stringstream newSS(valor);
            Type newValor;
            newSS >> newValor;
            Node<Type>* temp = new Node<Type>(newValor, nullptr, nullptr);
            temp->left = deserialize(ss);
            temp->right = deserialize(ss);
            return temp;
        }
    }

};


#endif 