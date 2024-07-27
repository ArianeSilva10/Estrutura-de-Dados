#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdexcept>
//struct que implementa um node 
// da lista duplamente encadeada
struct Node
{
    int data;// valor a ser guardado no node
    Node* prev; //ponteiro para o node anterior
    Node* next; // ponteiro para o proximo node

    //Construtor
    Node(const int& val, Node *ptrPrev, Node *ptrNext){
        data = val;
        prev = ptrPrev;
        next = ptrNext;
    }

    //Destrutor
    ~Node(){
        std::cout << "Liberado: " << data << "\n";
    }
};

    // classe que implementa uma lista
    // circular duplamente encadeada de inteiros
    class List{
        private:
            Node *m_head; //ponteiro para o sentinela
            unsigned m_size; //numero de elementos

        public:
            // Construtor default: cria lista vazia
            List(){
                m_head = new Node(0, nullptr, nullptr);
                m_head->next = m_head;
                m_head->prev = m_head;
            }

            //Função que retorna se  a lista está vazia
            bool empty()const{
                return m_size == 0;
            } 

            //Função que retorna o numero de
            //elementos na lista
            unsigned size(){
                return m_size;
            }

            // Função que insere no final da lista
            void push_back(const int& val){
                Node* aux = new Node(val, m_head->prev, m_head);
                m_head->prev->next = aux;
                m_head->prev = aux;
                m_size++;
            }

            // Remove um elemento do final da lista
            // Essa função não faz nada se a lista estiver vazia
            void pop_back(){
                if(!empty()){
                    Node *ptr = m_head->prev;
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    delete ptr;
                    m_size--;
                }
            }

            //Função que retorna uma referência 
            //para o primeiro elemento
            int& front(){
                if(empty()){
                    throw std::runtime_error("lista vazia");
                }
                else{
                    return m_head->next->data;
                }
            }
            const int& front()const{
                if(empty()){
                    throw std::runtime_error("lista vazia");
                }
                else{
                    return m_head->next->data;
                }
            }

            //Função que retorna o valor do ultimo
            int& back(){
                if(empty()){
                    throw std::runtime_error("lista vazia");
                }
                return m_head->prev->data;
            }
            const int& back()const{
                if(empty()){
                    throw std::runtime_error("lista vazia");
                }
                return m_head->prev->data;
            }

            //Função que limpa a lista:
            //deixa ela vazia novamente
            void clear(){
                if(empty()){
                    return;
                }
                while(m_head->next != m_head){
                    Node *aux = m_head->next;
                    m_head->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete aux;
                    m_size--;

                }
            }
            // Destrutor
            ~List(){
                clear(); // Libera os elementos
                delete m_head; // libera o sentinela
            }
    };


#endif