#ifndef LINELIST_H
#define LINELIST_H
#include "hourRoundList.h"
#include <iostream>


class lineListNode{
    public:
    std::string lineName;
    int numberLine;
    lineListNode *next;
    hourRoundList* parada;

    lineListNode() : next(nullptr){}
    lineListNode(std::string name, int number) : lineName(name), numberLine(number), next(nullptr){}
};


class lineList{
    public:
    lineListNode* firstNode;
    int size;
    hourRoundList* parada;

    //construtor
    lineList() : firstNode(nullptr), size(0), parada(nullptr) {}

    //destrutor
    ~lineList(){
        lineListNode* atualNode = firstNode;

        while (atualNode != nullptr) {
            lineListNode* nextNode = atualNode->next;
            delete atualNode;
            atualNode = nextNode;
        }
    }
};


lineList* criarListaSimples();

void inserirNaListaSimples(lineList* list, std::string lineName, int numberLine);

int BuscaLinha(lineList* linha,int &numeroLinha);

lineListNode* pegarDoIndexListaSimples(lineList* list, int index);

void apagarNoIndexListaSimples(lineList* list, int index);

void ImprimirListaSimples(lineList* list);

void removerParada(lineList* lista, int indiceLinha, const std::string& nomeParada);

void alterarParada(lineList* lista, int indiceLinha, const std::string& nomeParada, const std::string& novoNome, const std::string& novaSaida, const std::string& novaChegada);

void atribuirParadaEmLinha(lineList* linhas, int IndiceLinha, std::string nomeParada, std::string saidaParada, std::string chagadaParada);

void imprimirLinhasComParadas(lineList* linhas);
bool checkPassword (const std::string & corretPassword, const std::string & userPassword);//Funcao para verificar a senha em caso de manutencao de linhas e paradas


#endif