#ifndef BST_H
#define BST_H
#include <stdexcept>
#include <iostream>

/*******************************
 * Definicao do struct Node
 *******************************/
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r)
        : key(k), left(l), right(r) 
        { }

    ~Node() {
        std::cout << "Node removed: " << this->key << std::endl;
    }
};

/*******************************
 * class BST
 *******************************/
class BST { // classe BST (Binary Search Tree)
public:
    BST();
    ~BST();
    void bshow();
    void add(int key);       // Adicionar chave 
    bool contains(int key);  // contem chave key?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);                          // ----> implementar
    Node *maximum(Node *node);                          // ----> implementar
    Node *sucessor(Node *x, Node *raiz);                // ----> implementar
    Node *predecessor(Node *x, Node* raiz);             // ----> implementar
    Node *ancestral_sucessor(Node *x, Node *raiz);      // ----> implementar
    Node *ancestral_predecessor(Node *x, Node* raiz);   // ----> implementar
};

BST::BST() {  // Construtor
    root = nullptr; 
} 
    
BST::~BST() {  // Destrutor
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

// Esta funcao recebe um ponteiro para node e uma key e:
// (1) devolve nullptr caso key nao esteja na arvore;
// (2) devolve um ponteiro para o no contendo key caso contrario.
Node *BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key)
        return node;
    if(key > node->key)
        return search(node->right, key);
    else 
        return search(node->left, key);
} 

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}
 
// Esta funcao insere o no com chave key na arvore
// enraizada em node, somente se a chave key nao for repetida.
// Devolve um ponteiro para a raiz da nova arvore 
// enraizada em node.
Node *BST::add(Node *node, int key) {
    if(node == nullptr) { // Condicao de Parada
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    // Casos Gerais
    if(key > node->key)
        node->right = add(node->right, key);
    else if(key < node->key)
        node->left = add(node->left, key);
    return node;
} 

void BST::add(int key) {
    root = add(root, key);
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o minimo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::minimum(Node *node) {
    // TODO
    if (node == nullptr)
    {
        return nullptr;
    }else if (node->left == nullptr)
    {
        return node;
    }else
    {
        return minimum(node->left);
    }
}

// funcao publica. Devolve a chave minima da arvore
int BST::minimum() {
    // TODO
    Node* min = minimum(root);
    if (min == nullptr)
    {
        return 0;
    }else
    {
        return min->key;
    }
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o maximo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::maximum(Node *node) {
    // TODO
    if (node == nullptr)
    {
        return nullptr;
    }else if (node->right == nullptr)
    {
        return node;
    }else
    {
        return maximum(node->right);
    }
}

// Funcao publica. Devolve a chave maxima da arvore
int BST::maximum() {
    // TODO
    Node* max = maximum(root);
    if (max == nullptr)
    {
        return 0;
    }else
    {
        return max->key;
    }
}

// Devolve o ponteiro para o no sucessor do no x
// passado como parametro. A funcao tambem recebe
// como parametro a raiz da arvore.
Node *BST::sucessor(Node *x, Node *raiz) {
    // TODO
    Node* suc = nullptr;
    while (raiz != nullptr)
    {
        if (raiz->key  > x->key)
        {
            suc = raiz;
            raiz = raiz->left;
        }else
        {
            raiz = raiz->right;
        }
    }
    return suc;
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) {
    // TODO
    Node* suc = nullptr;
    while (raiz != nullptr)
    {
        if (raiz->key  > x->key)
        {
            suc = raiz;
            raiz = raiz->left;
        }else
        {
            raiz = raiz->right;
        }
    }
    return suc;
}

int BST::successor(int k) {
    // TODO
    Node* buscaK = search(root, k);
    if (buscaK == nullptr)
    {
        throw std::runtime_error("Chave nao encontrada");
    }
    Node* suc = ancestral_sucessor(buscaK,root);
    if (suc == nullptr)
    {
        throw std::runtime_error("Nao ha sucessor para a chave");
    }
    return suc->key;
}

// Retorna o ponteiro para o no antecessor do no x
// passado como parametro. A funcao tambem recebe 
// como parametro a raiz da arvore.
Node* BST::predecessor(Node *x, Node* raiz) {
    // TODO
    if (raiz == nullptr)
    {
        return nullptr;
    }
    Node* ant = nullptr;
    while (raiz != nullptr)
    {
        if (x->key > raiz->key)
        {
            ant = raiz;
            raiz = raiz->right;
        }else
        {
            raiz = raiz->left;
        }
    }
    return ant;
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) {
    // TODO
    if (raiz == nullptr)
    {
        return nullptr;
    }
    Node* ant = nullptr;
    while (raiz != nullptr)
    {
        if (x->key > raiz->key)
        {
            ant = raiz;
            raiz = raiz->right;
        }else
        {
            raiz = raiz->left;
        }
    }
    return ant;
}

int BST::predecessor(int k) {
    // TODO
    Node* busca = search(root,k);
    if (busca == nullptr)
    {
        throw std::runtime_error("Chave nao encontrada");
    }
    Node* antecessor = ancestral_predecessor(busca, root);
    if (antecessor == nullptr)
    {
        throw std::runtime_error("Nao ha antecessor para esta chave");
    }
    return antecessor->key;
}

#endif