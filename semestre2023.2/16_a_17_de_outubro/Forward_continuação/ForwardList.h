#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include <initializer_list>

/***********************************************************
 * @brief Classe que implementa a logica de
 * um node da lista simplesmente encadeada 
 */
class Node {
    // classes amigas de Node
    friend class ForwardList;
    friend class iterator_list;

    // atributos
    int   data;  // guarda o dado
    Node *next;  // ponteiro para o proximo

    // Construtor
    Node(const int& val, Node* nextPtr) {
        data = val;
        next = nextPtr;
    }

    // Destrutor
    //~Node() {
    //    std::cout << "nó liberado: " << data << '\n';
    //}

}; // final da classe Node


/***********************************************************
 * @brief Classe que implementa a logica de um iterador
 * de uma lista simplesmente encadeada
 */
class iterator_list {
    friend class ForwardList;
private:
    Node *ptr; // guarda um endereco para um Node

public:
    // Construtor: cria iterador apontando para um node
    iterator_list(Node *point) {
        ptr = point;
    }
    // Sobrecarga do operador*
    int& operator*() {
        return ptr->data;
    }
    // Sobrecarga do operador de igualdade
    // Dois iteradores são iguais quando eles 
    // apontam para o mesmo Node, ou seja,
    // quando seus ponteiros ptr são iguais
    bool operator==(const iterator_list& it) {
        return ptr == it.ptr;
    }
    // Sobrecarga do operador diferenca
    bool operator!=(const iterator_list& it) {
        return ptr != it.ptr;
    }
    // operador de pre-incremento
    // incrementa o iterador e o retorna
    iterator_list& operator++() {
        ptr = ptr->next;
        return *this;
    }
    // operador de pos-incremento
    // cria uma copia de si, incrementa a si, e retorna a copia
    iterator_list operator++(int) {
        iterator_list temp = *this;
        ptr = ptr->next;
        return temp;
    }

}; // fim da classe iterator_list


/*****************************************************************
 * @brief Classe que implementa uma lista simplesmente
 * encadeada de inteiros.
 */
class ForwardList {
private:
    // atributos
    Node *m_head {};     // aponta para o node sentinela
    Node *m_tail {};     // aponta para o ultimo elemento
    unsigned m_size {};  // numero de elementos na lista

public:
    // insere uma lista de ints depois do iterador
    iterator_list insert_after(iterator_list position, 
        std::initializer_list<int> lst) 
    {
        if(position.ptr == nullptr) {
            return position;
        }
        Node *temp = position.ptr;
        for(int e : lst) {
            temp->next = new Node(e, temp->next);
            if(temp == m_tail) {
                m_tail = temp->next;
            }
            temp = temp->next;
            m_size++;
        }
        return iterator_list(temp);
    }

    //Insere um novo elemento apos o iterador position. 
    // Retorna um iterador apontando para o elemento 
    // recem-inserido, ou retorna o proprio position 
    // se nenhum elemento tiver sido inserido.
    iterator_list insert_after(iterator_list position, 
        const int& val) 
    {
        if(position.ptr == nullptr) {
            return position;
        }
        Node *aux = new Node(val, position.ptr->next);
        position.ptr->next = aux;
        m_size++;
        if(position.ptr == m_tail) {
            m_tail = m_tail->next;
        }
        return iterator_list(aux);
    }

    // Remove o elemento apos o iterador position.
    // Retorna um iterador apontando para o elemento logo 
    // apos o elemento que foi removido. 
    // Se a funcao apagou o ultimo elemento,
    // o valor retornado eh o iterador end(). 
    // Se nenhum elemento for apagado, retorna position.
    iterator_list erase_after(iterator_list position) {
        if(position == end() || position.ptr == m_tail) {
            return position;
        }
        Node *aux = position.ptr->next;
        position.ptr->next = aux->next;
        if(aux == m_tail) {
            m_tail = position.ptr;
        }
        delete aux;
        m_size--;
        return iterator_list(position.ptr->next);
    }


    // retorna um iterador para o primeiro elemento
    iterator_list begin() {
        iterator_list it(m_head->next);
        return it;
    }
    // retorna um iterador para depois do ultimo elemento
    iterator_list end() {
        iterator_list it(nullptr);
        return it;
    }
    // retorna um iterador para o node anterior ao primeiro da lista
    iterator_list before_begin() {
        iterator_list it(m_head);
        return it;
    }

    // Construtor default: cria lista com 0 elementos
    ForwardList() {
        m_tail = m_head = new Node(0, nullptr);
    }
    // Função que insere um valor no início da lista
    void push_front(const int& val) {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        if(m_size == 0) {
            m_tail = aux;
        }
        m_size++;
    }
    // Função que imprime a lista no terminal
    void print() const {
        Node *temp = m_head->next;
        while(temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
    // Função que deixa a lista vazia novamente
    void clear() {
        Node *temp = m_head->next;
        while(temp != nullptr) {
            m_head->next = temp->next;
            delete temp;
            temp = m_head->next;
        }
        m_tail = m_head;
        m_size = 0;
    }
    // Destrutor
    ~ForwardList() {
        clear();
        delete m_head;
    } 
    // retorna o numero de elementos da lista
    unsigned size() const {
        return m_size;
    }
    // retorna se lista esta vazia
    bool empty() const {
        return m_size == 0;
    }

};

#endif