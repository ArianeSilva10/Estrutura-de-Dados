#ifndef BST_H
#define BST_H
#include <stdexcept>
#include "node.h"
using namespace std;

class BST { 
public:
    BST();
    ~BST();
    void add(int key);       // Adicionar chave 
    void remove(int key);    // Remover chave
    bool contains(int key);  // A arvore contem esta chave?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
    void bshow();            // Exibe a arvore
private:
    Node *root;
    Node *add(Node *node, int key);
    //Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *ancestral_sucessor(Node *x, Node *raiz);
    Node *ancestral_predecessor(Node *x, Node* raiz);
    Node *sucessor(Node *x, Node *raiz);
    Node *predecessor(Node *x, Node* raiz);
    Node *remove(int k, Node *node);
    Node *removeRoot(Node *node);
    void bshow(Node *node, std::string heranca);
};

// ******************************************************
// Implementacao da funcoes-membro da classe BST
// *******************************************************

// Construtor
BST::BST() {  
    root = nullptr; 
} 

// Destrutor
BST::~BST() {  
    root = clear(root);
} 

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {  
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

void BST::bshow() {
    bshow(root, "");
}

void BST::bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->left, heranca + "l");
}

/*
Node* BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key) {
        return node;
    }
    if(key < node->key)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// Retorna true se, e somente se, a chave esta na arvore
bool BST::contains(int key) {
    // versao 1
    if(search(root,key) == nullptr)
        return false;
    else
        return true;

    // versao 2
    //return (search(root,key) == nullptr) ? false : true;

    // versao 3
    //return search(root,key) != nullptr;
}
*/

// Funcao publica iterativa
bool BST::contains(int key) {
    Node *temp = root;
    while(temp != nullptr && temp->key != key) {
        if(key < temp->key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp != nullptr;
}

// Funcao privada
Node* BST::add(Node *node, int key) {
    if(node == nullptr) {
        return new Node(key, nullptr, nullptr);
    }
    if(node->key > key)
        node->left = add(node->left, key);
    else if(node->key < key)
        node->right = add(node->right, key);
    return node;
}

// Funcao publica
void BST::add(int key) {
    root = add(root, key);
}

#endif
