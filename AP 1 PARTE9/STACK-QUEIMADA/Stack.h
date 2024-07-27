#ifndef STACK_H
#define STACK_H

template <typename Type>
struct Node
{
    Type data;
    Node* next;

    Node(const Type& val, Node* nextPtr) : 
    data{val}, next{nextPtr}{}

    //~Node();
};

template <typename Type>
class Stack
{
private:
    Node<Type>* m_top{};
    unsigned m_size{};
public:
    Stack() = default;

    void push(const Type& val){
        m_top = new Node<Type>(val, m_top);
        ++m_size;
    }

    //desempilhar
    void pop(){
        if(m_size != 0){
            Node<Type>* aux = m_top;
            m_top = m_top->next;
            delete aux;
            --m_size;
        }
    }

    bool empty()const{
        return m_size == 0;
    }

    Type& top(){
        return m_top->data;
    }
/*
    ~Stack(){
        while (m_top != nullptr)
        {
            Node<Type>* aux = m_top;
            m_top = m_top->next;
            delete aux;
        }
        
    }*/
};


#endif