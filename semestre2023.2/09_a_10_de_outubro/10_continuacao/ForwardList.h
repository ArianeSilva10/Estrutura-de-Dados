#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>

// Classe que implementa  a logica de
// um nó da lista simplesmente encandeada
class Node{
    //classe amiga da Node
    friend class ForwardList;
    friend class iterator_list;

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
        //retorna um iterator para o primeiro elemento
        iterator_list begin(){
            iterator_list it(m_head->next);
            return it;
        }
        //retorna um iterator para depois do ultimo elemento (nulo)
        iterator_list end(){
            iterator_list it(nullptr);
            return it;
        }
        //retorna um iterador para o no anterior ao primeiro da lista
        iterator_list before_begin(){
            iterator_list it(m_head);
            return it;
        }

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

        //sobrecarga do operador[]
        // essa função não checa se o usuario passou 
        //um indice valido. Ela confia no usuário
        /*int& operator[](unsigned index){
            Node * aux = m_head->next;
            unsigned contador = 0;
            while(contador < index){
                aux = aux->next;
                contador++;
            }
            return aux->data;
        }*/
        //retorna o numero de elementos da lista
        unsigned size()const{
            return  m_size;
        }
}; // final da classe Node


//Classe que implementa a logica de um interador
//de uma lista simplesmente encandeada
class iterator_list{
    private:
        Node *ptr; //guarda um endereço para Node

    public:
        //Construtor
        iterator_list (Node *point){
            ptr = point;
        }
        //sobrecarga do operador*
        int& operator*(){
            return ptr->data;
        }
        //Sobrecarga  do operador de igualdade
        //Dois iteradores são iguais quando eles
        //apontam para o mesmo Node, ou seja, 
        // quando seus ponteiros ptr são iguais
        bool operator==(const iterator_list& it){
            return ptr == it.ptr;
        }
        //Sobrecarga de operador difereça
        bool operator!=(const iterator_list& it){
            return ptr != it.ptr;
        }
        //operador de pre- incremento
        //incrementa o iterador e o retorna
        iterator_list& operator++(){
            ptr = ptr->next;
            return *this;
        }
        //operador de pos incremento
        //cria uma copia de si, incrementa a si, e retorna a copia
        iterator_list operator++(int){
            iterator_list temp = *this;
            ptr = ptr->next;
            return temp;
        }
}; //fim da classe iterator_list



#endif