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

/*
IMPLEMENTAÇÃO
*/
// Concatena a lista atual com a lista lst.
// A lista lst eh modificada apos essa operacao.
// Por exemplo, seja l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8] e l2 = [ ]
// Restrição: está proibido usar funções auxiliares para resolver esta questão,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::concat(ForwardList& lst){
    if(lst.m_head->next == nullptr){
        return;
    }
    Node* aux = m_head->next;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    aux->next = lst.m_head->next;
    m_size += lst.m_size;
    lst.m_head->next = nullptr;
    lst.m_size = 0;
}

// Remove da lista todas as ocorrencias do Item x.
// Se a lista estiver vazia, esta funcao nao faz nada;
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::remove(const int& x){
    if(m_head->next == nullptr){
        return;
    }
    Node* aux = m_head;
    while(aux->next != nullptr){
        if(aux->next->data == x){
            Node* temp = aux->next;
            aux->next = temp->next;
            delete temp;
            m_size--;
        }
        else{
            aux = aux->next;
        }
    }
}


// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
ForwardList* ForwardList::clone(){
    ForwardList* Clone = new ForwardList();
    Node* aux = m_head->next;
    Node* auxClone = Clone->m_head;
    while(aux != nullptr){
        auxClone->next = new Node(aux->data, nullptr);
        aux = aux->next;
        auxClone = auxClone->next;
        Clone->m_size++;
    }
    return Clone;
}


// Copia os elementos do vector vec para o final da lista.
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void ForwardList::appendVector(const std::vector<int>& vec){
    if(vec.empty()){
        return;
    }
    Node* aux = m_head;
    while(aux->next != nullptr){
        aux = aux->next;
    }
    for(const int& i : vec){
        Node* temp = new Node(i, nullptr);
        aux->next = temp;
        aux = temp;
        m_size++;
    }
}

// Troca o conteudo dessa lista pelo conteudo de lst.
// Os tamanhos das listas podem diferir.
// Apos a chamada para esta funcao, os elementos nesta lista
// sao aqueles que estavam em lst antes da chamada,
// e os elementos de lst sao aqueles que estavam nesta lista.
void ForwardList::swap(ForwardList& lst){
    Node *aux = this->m_head;
    this->m_head = lst.m_head;
    lst.m_head = aux;

    unsigned size_aux = this->m_size;
    this->m_size = lst.m_size;
    lst.m_size = size_aux;
}

// Determina se a lista lst, passada por parametro, eh igual
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho
// e o valor do k-esimo elemento da primeira lista eh igual ao
// k-esimo valor da segunda lista.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
bool ForwardList::operator==(const ForwardList& lst) const{
    if(m_size != lst.m_size){
        return false;
    }
    Node *aux1 = m_head;
    Node *aux2 = lst.m_head;
    while(aux1->next != nullptr && aux2->next != nullptr){
        if(aux1->next->data != aux2->next->data){
            return false;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return true;
}
bool ForwardList::operator!=(const ForwardList& lst) const{
    if(m_size != lst.m_size){
        return true;
    }
    Node *aux1 = m_head;
    Node *aux2 = lst.m_head;
    while(aux1->next != nullptr && aux2->next != nullptr){
        if(aux1->next->data != aux2->next->data){
            return true;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return false;
}

// Inverte a ordem dos nós (o primeiro node passa a ser o último, o segundo passa a ser o penultimo, etc.)
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um número constante deles),
// mas nao pode alocar novos nós.
// Repetindo: está proibido chamar o operador new nesta questão.
// Restrição: Também não é permitido usar funções auxiliares nesta questão
void ForwardList::reverse(){
    if(m_head->next == nullptr){
        return;
    }
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *aux = m_head->next;

    while(aux->next != nullptr){
        next = aux->next;
        aux->next = prev;
        prev = aux;
        aux = next;
    }
    m_head->next = prev;
}