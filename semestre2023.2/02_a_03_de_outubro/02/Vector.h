/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 01-10-2023
 * @brief Classe que implementa uma lista linear sequencial de inteiros
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

template <typename T>
class Vector {
private:
    unsigned int m_size{};      // numero de elementos atualmente na lista
    unsigned int m_capacity{};  // capacidade atual da lista: o tamanho real do vetor interno
    T *m_vet{};               // ponteiro para o vetor de inteiros

public:
    // Construtor default: cria lista vazia e com capacidade zero
    // Complexidade: O(1)
    Vector() = default;

    // Construtor que recebe a capacidade
    // Complexidade: O(1)
    Vector(unsigned int cap);

    // Construtor de copia (copy constructor)
    // Foi preciso implementar nossa propria versao desse construtor
    // para que ele funcione da forma correta
    // Complexidade: O(1)
    Vector(const Vector& v);

    // Funcao que recebe um valor inteiro newCap 
    // que sera a nova capacidade.
    // Se m_capacity >= newCap, a funcao faz nada.
    // Caso contrario, a funcao aumenta a capacidade
    // do Vector para um valor maior ou igual a newCap
    // Complexidade: O(n)
    void reserve(unsigned int newCap);

    // Funcao que insere um elemento no final
    // da lista. Se a lista ficar cheia, ele
    // primeiro aumenta a capacidade da lista
    // e somente depois insere no final.
    // Complexidade: O(n) no pior caso
    void push_back(const T& val);

    // Funcao que recebe um índice i e retorna
    // o elemento que esta no índice i.
    // Se o indice nao existir na lista, essa funcao
    // vai lancar uma excecao.
    // Complexidade: O(1)
    T& at(unsigned int i);

    // Versao const da funcao at()
    // Complexidade: O(1)
    const T& at(unsigned int i) const;

    // Destrutor: libera memoria alocada
    // Complexidade: O(1)
    ~Vector();

    // Funcao const que retorna o numero de elementos na lista
    // Complexidade: O(1)
    unsigned int size() const;

    // Funcao const que retorna a capacidade total da lista
    // Complexidade: O(1)
    unsigned int capacity() const;

    // Funcao const que retorna true se e somente se a lista estiver vazia
    // Complexidade: O(1)
    bool empty() const;

    // sobrecarga do operador de indexacao
    // recebe um indice i e retorna o elemento no indice i
    // Se o indice não estiver dentro do intervalo, 
    // o comportamento dessa funcao é indeterminado.
    // Complexidade: O(1)
    T& operator[](unsigned int i);

    // versao const do operador[]
    // Complexidade: O(1)
    const T& operator[](unsigned int i) const;

    // Funcao que remove o ultimo elemento da lista, se a lista nao estiver vazia.
    // Se a lista estiver vazia, entao essa funcao nao faz nada.
    // O que essa funcao faz de fato eh apenas decrementar o atributo m_size.
    // Complexidade: O(1)
    void pop_back();

    //Sobrecarga do operador de atribuição
    // Faz uma atribuição entre Vectors
    Vector& operator=(const Vector& v);

    // Compara dois vectos
    // Retorna 'true' se e somente se, os vetores são identicos
    //Dois vectores são identicos se tem o mesmo tamanho 
    // e os elementos correspondentes tem o mesmo valor
    bool operator==(const Vector& v);

};
template <typename T>
bool Vector<T>::operator==(const Vector& v){
    if(m_size != v.m_size){
        return false;
    }
    for(int i =0; i < m_size; i++){
            if(m_vet[i] != v.m_vet[i]){
                return false;
            }
    }
    return true;
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& v){
    if(this != &v){
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        delete[] m_vet;
        m_vet = new T[m_capacity];
        for(int i = 0; i < m_size; i++){
            m_vet[i] = v.m_vet[i];
        }
    }
    return *this;
}



// ----------------------------------------------------------
// Implementacao das funcoes-membro da classe Vector
// ----------------------------------------------------------
template <typename T>
Vector<T>::Vector(unsigned int cap) 
    : m_size{0}, m_capacity{cap}
{
    m_vet = new T[m_capacity];
}
template <typename T>
Vector<T>::Vector(const Vector& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vet = new T[m_capacity];
    for(unsigned int i = 0; i < m_size; ++i) {
        m_vet[i] = v.m_vet[i];
    }
}
template <typename T>
void Vector<T>::reserve(unsigned int newCap) {
    if(m_capacity < newCap) {
        m_capacity = newCap;
        T *aux = new T[m_capacity];
        for(unsigned int i = 0; i < m_size; ++i) {
            aux[i] = m_vet[i];
        }
        delete[] m_vet;
        m_vet = aux;
    }
}
template <typename T>
void Vector<T>::push_back(const T& val) {
    if(m_size == m_capacity) {  // aumenta de precisar
        reserve(2 * (m_capacity + 1));
    }
    m_vet[m_size] = val; // insere
    m_size++;            // incrementa m_size
}
template <typename T>
T& Vector<T>::at(unsigned int i) {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}
template <typename T>
const T& Vector<T>::at(unsigned int i) const {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}
template <typename T>
Vector<T>::~Vector() {
    delete[] m_vet;
}
template <typename T>
unsigned int Vector<T>::size() const {
    return m_size;
}
template <typename T>
unsigned int Vector<T>::capacity() const {
    return m_capacity;
}
template <typename T>
bool Vector<T>::empty() const {
    return m_size == 0;
}
template <typename T>
T& Vector<T>::operator[](unsigned int i) {
    return m_vet[i];
}
template <typename T>
const T& Vector<T>::operator[](unsigned int i) const {
    return m_vet[i];
}
template <typename T>
void Vector<T>::pop_back() {
    if(m_size > 0) {
        m_size--;
    }
}

#endif // VECTOR_H