#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template<typename Type>
struct Node
{
    Type data;
    Node* next;

    Node(const Type& val, Node* NextPtr): data(val), next(NextPtr){};
};

template<typename Type>
class Queue
{
private:
    Node<Type>* m_head{};
    Node<Type>* m_tail{};
    unsigned m_size{};

public:
    Queue() = default;

    void push(const Type& val){
        if (m_size == 0)
        {
            m_head = m_tail = new Node<Type>(val, nullptr);
        }
        else{
            m_tail->next = new Node<Type>(val, nullptr);
            m_tail = m_tail->next;
        }
        m_size++;
    }

    void pop(){
        if (m_size != 0)
        {
            Node<Type>* aux = m_head;
            m_head = m_head->next;
            delete aux;
            m_size--;
            if (m_head == nullptr)
            {
                m_tail = nullptr;
            }
        }
    }
    Type& front(){
        if (m_size == 0)
        {
            throw std::out_of_range("Fila vazia");
        }else
        {
            return m_head->data;
        }
    }
    ~Queue(){
        while (m_head != nullptr)
        {
            Node<Type>* aux = m_head;
            m_head = m_head->next;
            delete aux;
        }
        
    }
};

#endif