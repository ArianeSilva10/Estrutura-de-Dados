#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>

// Classe que implementa  a logica de
// um nó da lista simplesmente encandeada
class Node{
    //classe amiga da Node
    friend class ForwardList;

    //atributos
    int data; // guarda o dado
    Node *next; // ponteiro para o proximo

    //Construtor
    Node(const int& val, Node* nextPtr){
        data = val;
        next = nextPtr;
    }
    //Destrutor
    ~Node(){
        std::cout << "nó liberado: " << data << '\n';
    }
};

//Classe que implementa uma lista simplesmente 
//encandeada de inteiros
class ForwardList{
    private:
        Node *m_head{}; //aponta para o nó sentinela
        Node *m_tail{}; // aponta para o ultimo elemento
        unsigned m_size{}; //numero de elementos
    public:
        // Construtor default: cria lista com 0 elementos
        ForwardList(){
            m_tail = m_head = new Node(0, nullptr);
        }
        //Função que insere um valor no inicio da lista
        void pushfront(const int& val){
            Node *aux = new Node(val, m_head->next);
            m_head ->next = aux;
            if(m_size == 0){
                m_tail = aux;
            }
            m_size++;
        }

        // Função que imprime a lista no terminal
        void print(){
            Node *temp = m_head->next;
            while(temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
        //Função q deixa a lista vazia novamente
        void clear(){
            Node *temp = m_head->next;
            while(temp != nullptr){
                m_head->next = temp->next;
                delete temp;
                temp = m_head->next;
            }
            m_tail = m_head;
            m_size = 0;
        }

        //Destrutor
        ~ForwardList(){
            clear();
            delete m_head;
        }
};


#endif