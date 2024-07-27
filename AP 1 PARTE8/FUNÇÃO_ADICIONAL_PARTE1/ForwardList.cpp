/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * Voce deve implementar as funcoes que faltam ao final deste arquivo
 ************************************************************************/
#include <iostream>
#include "Node.h"
#include "ForwardList.h"

// *********************************************************
// Implementacao das funcoes-membro da classe ForwardList
// *********************************************************

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->data, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

void ForwardList::print() const {
    Node *temp = m_head->next;
    while(temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}

    // --------------------------------------------------------- //
    // ----------- funcoes adicionais - parte 1 ---------------- //
    // --------------------------------------------------------- //

    // insere um elemento no inicio da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::push_front(const int& val){
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        if(m_size == 0){
            m_size++;
            m_head->next = aux;
        }
        m_size++;
    }

    // retorna uma referencia para o primeiro elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    int& ForwardList::front(){
        return m_head->next->data;
    }
    const int& ForwardList::front() const{
        return m_head->next->data;
    }

    // deleta o primeiro elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::pop_front(){
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
        m_size--;
    }

    // retorna uma referencia para o ultimo elemento na lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    int& ForwardList::back(){
        Node *aux = m_head->next;
        Node *back = nullptr;
        while(aux != nullptr){
            back = aux;
            aux = aux->next;
        }
        if(back != nullptr){
            return back->data;
        }
        else{
            return m_head->data;
        }
    }
    const int& ForwardList::back() const{
        Node *aux = m_head->next;
        Node *back = nullptr;
        while(aux != nullptr){
            back = aux;
            aux = aux->next;
        }
        if(back != nullptr){
            return back->data;
        }
        else{
            return m_head->data;
        }
    }
    
    // insere um elemento no final da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::push_back(const int& val){
        Node *temp = m_head->next;
        Node *aux = new Node(val, nullptr);

        if(temp == nullptr){
            m_head->next = aux;
        }
        else{
            while(temp->next != nullptr){
                temp = temp->next;
            }
        temp->next = aux;
        }
        m_size++;
    }

    // deleta o ultimo elemento da lista
    // Restricao: estar proibido usar funções auxiliares nesta questao,
    // inclusive qualquer dos operadores sobrecarregados
    void ForwardList::pop_back(){
        if(m_head->next != nullptr){
            Node *aux = m_head->next;
            Node *temp = aux->next;

            if(temp == nullptr){
                delete aux;
                m_head->next = nullptr;
            }
            else{
                while(temp->next != nullptr){
                    aux = temp;
                    temp = temp->next;
                }
            delete temp;
            aux->next = nullptr;
            }
        m_size--;
        }
    }