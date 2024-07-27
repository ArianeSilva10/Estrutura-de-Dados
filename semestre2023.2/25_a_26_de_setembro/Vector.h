/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 2023-09-26
 * Classe que implementa uma lista linear de inteiros 
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
private:
    unsigned int m_size{};     // numero de elementos na lista
    unsigned int m_capacity{}; // capacidade total da lista
    int* m_vet{};              // ponteiro para a lista

public:
    // Construtor vazio (default)
    Vector() = default;
    // Construtor 
    Vector(unsigned int capInicial) {
        std::cout << "construtor com 1 arg chamado\n";
        m_capacity = capInicial;
        m_vet = new int[m_capacity];
    }
    // Construtor de copia: cria um novo vector
    // a partir de um vector antigo
    Vector(const Vector& v) {
        std::cout << "copy construstor chamado\n";
        m_size = v.m_size;
        m_capacity = v.m_capacity;
        m_vet = new int[m_capacity];
        for(unsigned int i{0}; i < m_size; ++i) {
            m_vet[i] = v.m_vet[i];
        }
    }
    // Destructor: libera o array que foi alocado dinamicamente
    ~Vector() {
        delete[] m_vet;
        std::cout << "destrutor chamado\n";
    }
    // Funcao que tenta aumentar a capacidade da lista.
    // Se a lista tiver m_capacity >= newCap entao
    // essa funcao nao faz nada.
    // Se m_capacity < newCap entao a capacidade da lista
    // é aumentada e a funcao garante que os elementos
    // originais permanecem nas mesmas posicoes.
    void resize(unsigned int newCap) {
        if(m_capacity < newCap) {
            m_capacity = newCap;
            int *aux = new int[m_capacity];
            for(unsigned i{0}; i < m_size; ++i) {
                aux[i] = m_vet[i];
            }
            delete[] m_vet;
            m_vet = aux;
        }
    }
    // Insere um elemento no final da lista
    // Se a lista estiver cheia, ele aumenta
    // a capacidade antes de inserir o elemento
    void push_back(int elem) {
        // se estiver cheia, dobra o tamanho
        // e ajusta os atributos de acordo.
        if(m_size == m_capacity) {
            resize(2 * (m_capacity+1));
        }
        m_vet[m_size] = elem;
        m_size++;
    }
    // Função que recebe um índice
    // e retorna o elemento naquele índice.
    // Se o índice não estiver dentro do intervalo,
    // a função vai lançar uma exceção.
    int& at(unsigned int i) {
        if(i < m_size) {
            return m_vet[i];
        }
        else {
            throw std::out_of_range("indice invalido");
        }
    }
    // retorna o numero de elementos
    unsigned int size() {
        return m_size;
    }
    // Recebe um indice e retorna uma referencia
    // para o elemento naquele indice.
    // Se o indice nao existir, 
    // a funcao nao faz nada: 
    // fica por sua conta e risco.
    int& operator[](int index) {
        return m_vet[index];
    }

};

#endif // VECTOR_H