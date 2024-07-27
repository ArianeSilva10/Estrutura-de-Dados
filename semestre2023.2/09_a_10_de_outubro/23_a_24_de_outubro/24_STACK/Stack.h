#ifndef STACK_H
#define STACK_H

template<typename Type>
struct Node
{
    Type data; //valor guardado
    Node* next; //ponteiro para o proximo na pilha

    Node(const Type& val, Node* ptrNext) : data{val}, next{ptrNext}
    {}

    ~Node(){
        std::cout << "Liberado: " << data << std::endl;
    }
};

/*
Classe generica que implementa uma ED pilha
*/
template<typename Type>
class Stack{
    private:
        //ponteiro para o topo da pilha
        Node<Type>* m_top{};

        //numero de elementos na pilha
        unsigned m_size{};

    public:
    //construtor  default
    Stack() = default;

    //construtor de copia
    Stack(const Stack& stack){
        Node<Type>* aux2{};
        Node<Type>* aux = stack.m_top;
        while(aux != nullptr){
            if(aux == stack.m_top){
                aux2 = m_top = new Node<Type>(aux->data, nullptr);
            }
            else{
                aux2->next = new Node<Type>(aux->data, nullptr);
                aux2 = aux2->next;
            }
            aux = aux->next;
        }
        m_size = stack.m_size;
    }

    //insere no topo da pilha
    void push(const Type& val){
        m_top = new Node<Type>(val, m_top);
        ++m_size;
    }
    //Desempilha do topo
    void pop(){
        if(m_size != 0){
            Node<Type> *aux = m_top;
            m_top = m_top->next;
            delete aux;
            --m_size;
        }
    }
    // retorna true se e somente se pilha estiver vazia
    bool empty()const{
        return m_size == 0;
    }

    //retorna o numero de elementos na pilha
    unsigned size()const{
        return m_size;
    }

    //retorna uma ref para o elemento no topo
    Type& top(){
        return m_top->data;
    }

    const Type& top()const{
        return m_top->data;
    }

    ~Stack(){
        while (m_top != nullptr)
        {
            Node<Type> *aux = m_top;
            m_top = m_top->next;
            delete aux;
        }
        
    }
};

#endif