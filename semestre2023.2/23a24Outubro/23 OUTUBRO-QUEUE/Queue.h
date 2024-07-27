#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include "Node.h"

/**
 * @brief Classe que implementa uma fila
 * com politica de acesso FIFO (First-in First-out) 
 */
template <typename Type>
class Queue {
private:
    Node<Type>* m_head {}; // ponteiro para o primeiro
    Node<Type>* m_tail {}; // ponteiro para o ultimo
    unsigned    m_size {}; // numero de elementos

public:
    // Construtor: criar uma fila vazia
    Queue() = default;

    // Funcao que insere um elemento na fila
    // Insere no final!
    void push(const Type& val) {
        if(m_size == 0) {
            m_head = m_tail = new Node<Type>(val, nullptr);
        }
        else {
            m_tail->next = new Node<Type>(val, nullptr);
            m_tail = m_tail->next;
        }
        m_size++;
    } 

    // Remover elemento da fila
    void pop() {
        if(m_size != 0) {
            Node<Type>* aux = m_head;
            m_head = m_head->next;
            delete aux;
            m_size--;
            if(m_head == nullptr) m_tail = nullptr;
        }
    }

    // Acessa o valor elemento no inicio da fila
    Type& front() {
        if(m_size == 0) { // fila vazia
            throw std::runtime_error("empty queue");
        }
        else { // fila nao vazia
            return m_head->data;
        }
    }

    const Type& front() const {
        if(m_size == 0) { // fila vazia
            throw std::runtime_error("empty queue");
        }
        else { // fila nao vazia
            return m_head->data;
        }
    }

    // Retorna true se e somente se fila vazia
    bool empty() const {
        return m_size == 0;
    }

    // Destrutor
    ~Queue() {
        while(m_head != nullptr) {
            Node<Type>* aux = m_head;
            m_head = m_head->next;
            delete aux;
        }
    }
    
    unsigned size() const{
        return m_size;
    }

    Type& back(){
        if(m_size == 0) { // fila vazia
            throw std::runtime_error("empty queue");
        }
        else{
            return m_tail->data;
        }
    }

    const Type& back()const{
        if(m_size == 0) { // fila vazia
            throw std::runtime_error("empty queue");
        }
        else{
            return m_tail->data;
        } 
    }

};

#endif