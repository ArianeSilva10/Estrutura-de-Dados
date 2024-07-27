#ifndef HOURROUNDLIST_H
#define HOURROUNDLIST_H
#include <iostream>

class hourRoundNode{
    public:
    std::string nome;
    std::string saida;
    std::string chegada;

    /* Logica */
    hourRoundNode* next;
    hourRoundNode* prev;

    //Construtor
    hourRoundNode() : next(nullptr), prev(nullptr){}
    hourRoundNode(std::string Nome, std::string Saida, std::string Chegada)
    : nome(Nome), saida(Saida), chegada(Chegada), next(nullptr), prev(nullptr){}
};

class hourRoundList{
    public:
    hourRoundNode* firstNode;
    hourRoundNode* lastNode;
    int size;

    //Construtor
    hourRoundList() : firstNode(nullptr), lastNode(nullptr), size(0){}

    //destrutor
    ~hourRoundList(){
        hourRoundNode* atualNode = firstNode;
        while (atualNode != nullptr)
        {
            hourRoundNode* nextNode = atualNode->next;
            delete atualNode;
            atualNode = nextNode;
        }
        firstNode = nullptr;
        lastNode = nullptr;
        size = 0;
    }

};

hourRoundList* criarListaCircular();

void inserirNaListaCircular(
    hourRoundList* list,
    std::string nome,
    std::string saida,
    std::string chegada);

void ImprimirListaCircular(hourRoundList* list);

#endif

