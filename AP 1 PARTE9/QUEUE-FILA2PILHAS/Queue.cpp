//#include "Queue.h"
#include <iostream>

//IMPLEMENTAÇÃO QUEUE
template<typename Type>
void Queue<Type>::push(const Type& val){
    deposito.push(val);
    ++m_size;
}

template<typename Type>
void Queue<Type>::pop(){
    if (empty())
    {
        throw std::out_of_range("Fila vazia");
    }
    if (prateleira.empty())
    {
        deposito.transfer(prateleira,deposito);
    }
    prateleira.pop();
    --m_size;
}

template<typename Type>
Type& Queue<Type>::front(){
    if (empty())
    {
        throw std::out_of_range("Fila vazia");
    }
    if (prateleira.empty())
    {
        deposito.transfer(prateleira, deposito);
    }
    return prateleira.top();
}


//IMPLEMENTAÇÃO STACK
template<typename Type>
//função para apagar o elemento da pilha(m_top)
void Stack<Type>::pop(){
    if(m_size != 0){
            Node<Type>* aux = m_top;
            m_top = m_top->next;
            delete aux;
            --m_size;
        }
}

template<typename Type>
//função para a pilha deposito
void Stack<Type>::push(const Type& val){
    m_top = new Node<Type>(val, m_top);
    ++m_size;
}


template<typename Type>
//Função caso a prateleira esteja vazia e recebe tudo da pilha deposito
void Stack<Type>::transfer(Stack& prateleira, Stack& deposito){
    while (!deposito.empty())
    {
        Type val = deposito.top();
        deposito.pop();
        prateleira.push(val);
    }
}
//implementação destrutor
template<typename Type>
Stack<Type>::~Stack(){
    while(m_top != nullptr) {
        Node<Type> *aux = m_top;
        m_top = m_top->next;
        delete aux;
    }
}
