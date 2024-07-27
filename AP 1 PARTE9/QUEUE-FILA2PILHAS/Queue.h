#ifndef QUEUE_H
#define QUEUE_H

template<typename Type>
struct Node
{
    Type data;
    Node *next;

    //construtor
    Node(const Type val, Node* nextPtr){
        data = val;
        next = nextPtr;
    }
};

//classe das pilhas
template <typename Type>
class Stack
{
private:
    Node<Type>* m_top{};
    unsigned m_size{};

public:
    Stack() = default;

    //verifica se está vazia
    bool empty(){
        return m_size == 0;
    }

    //retorna o m_top
    Type& top(){
        return m_top->data;
    }

    //função para apagar o elemento da pilha(m_top)
    void pop();

    //função para a pilha deposito
    void push(const Type& val);


    //destrutor
    ~Stack();

    //Função caso a prateleira esteja vazia e recebe tudo da pilha deposito
    void transfer(Stack<Type>& prateleira, Stack& deposito);
};


//classe da fila
template<typename Type>
class Queue
{
private:
    unsigned m_size;
    Stack<Type> deposito;
    Stack<Type> prateleira;
public:
    //construtor
    Queue() = default;

    //destrutor
    //~Queue();

    //adicionar  um elemento à fila
    void push(const Type& val);

    //remover o elemento da fila(primeiro elemento)
    void pop();

    //retorna o primeiro da fila
    Type& front();

    //verifica se esta vazio
    bool empty(){
        return m_size == 0;
    }
};
#include "Queue.cpp"
#endif