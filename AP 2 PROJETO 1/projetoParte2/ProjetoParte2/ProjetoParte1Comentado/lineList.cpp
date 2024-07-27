/*
DUPLA:
Raíssa Ívyna Moreira de Oliveira - 553679
Francisca Ariane dos Santos da Silva - 554930
*/
#include "lineList.h"
#include "hourRoundList.h"
#include <iostream>
#include <fstream>
using namespace std;


//Funcao que cria uma lista simples de Linhas de Onibus
// Ela aloca memoria para uma instancia de lineList, inicializa
// e retorna um ponteiro para a lista que foi criada
/* Complexidade O(1), pois possui operacoes fixas, com alocacao de
memoria e inicializacao da variaveis. O(1) + O(1) + O(1) + O(1) = O(4)
O(4) equivale a constante, portanto O(4) = O(1).
*/
lineList* criarListaSimples(){
    lineList* listHead = new lineList; //O(1)
    listHead->firstNode = NULL; //O(1)
    listHead->size = 0; // O(1)
    return listHead; // O(1)
}

//faz a busca da função com seu numero da linha retornando
// a posição na qual a linha está
/*
A complexidade no pior caso dessa função é O(n), devido ao while onde
pode chegar até o ultimo nó.
*/
int BuscaLinha(lineList* linha,int &numeroLinha){
    lineListNode* list = linha->firstNode; //O(1)
    int aux = 0; //O(1)
    while (list != nullptr && list->numberLine != numeroLinha) // O(n)
    {
        list = list->next; //O(1)
        aux++; //O(1)
    }
    if (list == nullptr) // O(1)
    {
        return -1;//O(1)
    }
    else{
        return aux; // O(1)
    }
}

//Funcao que permite adicionar uma nova Linha de Onibus 
// a lista de Linhas criada criando um novo no de linha
// e inserindo no final da lista
/*
No pior caso, a complexidade dessa funcao eh O(n) pois ela verifica se a lista
esta vazia e assim faz O(1) em operacao, ja se nao estiver vazia, a funcao percorre
para encontrar o ultimo no da lista (O(n)), sendo n o numero de nos da lista
*/
void inserirNaListaSimples(lineList* list ,string lineName, int numberLine){
    lineListNode* listNode = new lineListNode; //O(1)
    listNode->lineName = lineName; //O(1)
    listNode->numberLine = numberLine; //O(1)
    listNode->next = nullptr; // O(1)

    if(list->firstNode == nullptr){ //O(1)
        list->firstNode = listNode; // O(1)
        list->size = 1; // O(1)
        return; //O(1)
    }

    lineListNode* lastObject = list->firstNode; //O(1)
    while (lastObject->next != nullptr){ // O(n)
        lastObject = lastObject->next; // O(1)
    }
    
    lastObject->next = listNode; //O(1)
    list->size = list->size + 1; //O(1)
}


//Essa funcao busca por uma Linha de Onibus especifica 
// com base no indice dela, retornando um ponteiro para 
// o no no indice especificado ou nullptr se estiver fora 
// dos limites
/*
No pior caso, a Complexidade dessa função é O(n) devido ao Looping
while onde percorre o numero de nó da Lista.
As demais operações como comparações são constantes, sendo assim O(1)
*/
lineListNode* pegarDoIndexListaSimples(lineList* list, int index){
    lineListNode* obj = list->firstNode; // O(1)

    if(obj == NULL){ //O(1)
        return NULL; // O(1)
    }

    if(index == 0){ //O(1)
        return obj; // O(1)
    }
    int ct_index = 0; //O(1)

    while(ct_index != index && (list != nullptr)){ // O(n)
        obj = obj->next; //O(1)
        ct_index++; //O(1)
    }

    return obj; //O(1)
}

//Essa funcao remove uma Linha de Onibus (no) especifico com 
// base no seu indice, liberando memoria alocada para o no de Linha
// e atualiza os ponteiros
/*
No pior caso, a função tem de complexidade O(n) devido ao while que percorre 
o numero de nós da Lista de Linhas. As demais funções são operações constantes
sendo assim O(1).
*/
void apagarNoIndexListaSimples(lineList* list, int index){
    lineListNode* obj = list->firstNode; //O(1)
    lineListNode* prev = obj; // O(1)

    if(obj->next == NULL){ //O(1)
        list->firstNode = NULL; // O(1)
        delete obj; // O(1)
        list->size=0; // O(1)
        return; // O(1)
    }

    if(index == 0){ // O(1)
        obj = obj->next; // O(1)
        
        list->firstNode = obj; // O(1)
        delete prev;// O(1)
        list->size--; // O(1)
        return; // O(1)
    }

    int ct_index = 0; // O(1)
    
    while(ct_index != index && (list != nullptr)){ // O(n)
        prev = obj; // O(1)
        obj = obj->next; // O(1)
        ct_index++; // O(1)
    }

    prev->next = obj->next; // O(1)
    delete obj; // O(1)
    list->size--; // O(1)

}


//Imprime a lista de Linhas de Onibus
/*
A complexidade dessa função no pior caso é O(n) por percorrer a Lista de nós (Linhas)
*/
void ImprimirListaSimples(lineList* list) {
    lineListNode* currentNode = list->firstNode; // O(1)

    while (currentNode != nullptr) { //O(n)
        std::cout << "Linha: " << currentNode->numberLine << endl << currentNode->lineName << endl; // O(1)

        currentNode = currentNode->next; // O(1)
    }
}

//Funcao que cria uma lista circular de 
// paradas para um Linha de onibus especifica
// aloca memoria para hourRoundList e inicialiaza
/*
A complexidade dessa função é O(1). Ela possui operações constantes 
resultando em complexidade constante
*/
hourRoundList* criarListaCircular(){
    hourRoundList* list = new hourRoundList; // O(1)
    list->firstNode = NULL; // O(1)
    list->lastNode = NULL; // O(1)
    list->size = 0; // O(1)
    return list; // O(1)
}

//Funcao que adiciona uma nova parada a lista Circular depois de criada
// ela adiciona um novo no de parada e o insere no final da lista
/*
A complexidade dessa função é O(1) por manter operações constantes, por ser
um conjunto de O(1) então seu todo permanece O(1)
*/
void inserirNaListaCircular(hourRoundList* list, string nome, string saida, string chegada){
    hourRoundNode* node = new hourRoundNode; // O(1)

    node->chegada = chegada; // O(1)
    node->nome = nome; // O(1)
    node->saida = saida; // O(1)

    if(list->firstNode == nullptr){
    }
    else{
    }
    if(list->firstNode == nullptr){ // O(1)
        node->next = node; // O(1)
        list->firstNode = node; // O(1)
        list->lastNode = node; // O(1)
        node->prev = node; // O(1)
        list->size++;
    }
    else{
        list->lastNode->next = node; // O(1)
        list->firstNode->prev = node; // O(1)
        node->prev = list->lastNode; // O(1)
        node->next = list->firstNode; // O(1)

        list->lastNode = node; // O(1)
    }
    list->size ++; // O(1)
}


//Funcao que remove uma parada especifica em uma Linha de Onibus
//Ela faz a busca com base no nome da parada e a remove da lista Circular
/*
A complexidade é dada pela busca de Linhas e de Paradas (O(n+m)).
primeiramente O(n) pela busca de Linhas a partir da função pegardoIndexListaSimples
e para a busca de paradas O(n), assim O(m), por percorrer a Lista de paradas na Linha
assim sendo : O(n+m)
*/
void removerParada(lineList* lista, int indiceLinha, const std::string& nomeParada){
    lineListNode* linha = pegarDoIndexListaSimples(lista, indiceLinha); // O(n)
    
    if(linha != nullptr){
        hourRoundList* paradas = linha->parada; // O(1)

        if(paradas != nullptr){
            hourRoundNode* paradaAtual = paradas->firstNode; // O(1)
            hourRoundNode* paradaAnterior = nullptr; // O(1)

            while (paradaAtual != nullptr) //O(n)
            {
                if(paradaAtual->nome == nomeParada){  // O(1)
                    if(paradaAnterior == nullptr){ // O(1)
                        paradas->firstNode = paradaAtual->next; // O(1)
                        delete paradaAtual; // O(1)
                        paradas->size--; // O(1)
                        cout << "Parada removida da linha " << linha->numberLine << endl << linha->lineName << endl; // O(1)
                        return; // O(1)
                    }
                    else{
                        paradaAnterior->next = paradaAtual->next; // O(1)
                        delete paradaAtual; // O(1)
                        paradas->size--; // O(1)
                        cout << "Parada removida da linha " << linha->numberLine << endl << linha->lineName << endl; // O(1)
                        return; // O(1)
                    }
                }
                paradaAnterior = paradaAtual; // O(1)
                paradaAtual = paradaAtual->next; // O(1)
            }
            //se chegou ate aqui eh porque a parada nao foi encontrada
            cout << "Parada nao encontrada na Linha " << linha->numberLine << endl << linha->lineName << endl; // O(1)
        }
        //Caso em que a linha esteja vazia, sem paradas
        else{
            cout << "A Linha " << linha->numberLine << endl << linha->lineName << " nao possui paradas" << endl; // O(1)
        }
    }
    //Situacao em que nao encontra a linha a qual deseja remover a parada
    else{
        cout << "Linha nao encontrada na posicao: " << indiceLinha << endl; // O(1)
    }
}

//Funcao que altera os dados de uma parada especifica em uma Linha de Onibus
// Ela faz a busca com base no nome da parada e apos isso atualiza seus dados
/*
Da mesma forma da função anterior, ela percorre primeiro as Linhas O(n) e depois as
paradas O(m), sendo  as demais operações constantes O(1).
Portanto a Complexidade dela é O(n+m)
*/
void alterarParada(lineList* lista, int indiceLinha, const std::string& nomeParada, const std::string& novoNome, const std::string& novaSaida, const std::string& novaChegada) {
    lineListNode* linha = pegarDoIndexListaSimples(lista, indiceLinha); //O(n)

    if (linha != nullptr) {
        hourRoundList* paradas = linha->parada; // O(1)

        if (paradas != nullptr) {
            hourRoundNode* paradaAtual = paradas->firstNode; // O(1)

            while (paradaAtual != nullptr) {//O(n)
                //alteracao dos dados no looping
                if (paradaAtual->nome == nomeParada) { // O(1)
                    paradaAtual->nome = novoNome; // O(1)
                    paradaAtual->saida = novaSaida; // O(1)
                    paradaAtual->chegada = novaChegada; // O(1)
                    cout << "Dados da parada alterados com sucesso na Linha " << linha->lineName << endl; // O(1)
                    return; // O(1)
                }
                paradaAtual = paradaAtual->next; // O(1)
            }
            // Se chegou até aqui, a parada não foi encontrada
            cout << "Parada não encontrada na Linha "<< linha->numberLine << endl << linha->lineName << endl; // O(1)
        }
        //caso em que a linha não possua paradas
        else {
            cout << "A Linha "<< linha->numberLine << endl << linha->lineName << " não possui paradas" << endl; // O(1)
        }
    }
    // Situação em que não encontra a linha a qual deseja alterar a parada
    else {
        cout << "Linha não encontrada na posição: " << indiceLinha << endl; // O(1)
    }
}

//Funcao que permite adicionar uma nova parada a uma Linha de Onibus especifica
// Criando um novo no de parada e adicionando a lista Circular de paradas
/*
A complexidade dessa função é O(n) por percorrer apenas a Lista de Linhas ao 
chamar a função pegarDoIndexListaSimples. As demais operações permanecem costantes
O(1)
*/
void atribuirParadaEmLinha(lineList* linhas, int indiceLinha, std::string nomeParada, std::string saidaParada, std::string chegadaParada){
    if(indiceLinha < 0 || indiceLinha >= linhas->size){ // O(1)
        std::cout << "Indice de linha invalido." << std::endl; // O(1)
        return; // O(1)
    }
    // Cria uma nova parada
    hourRoundNode* novaParada = new hourRoundNode(); // O(1)
    novaParada->nome = nomeParada; // O(1)
    novaParada->saida = saidaParada; // O(1)
    novaParada->chegada = chegadaParada; // O(1)
    novaParada->next = nullptr; // O(1)

    // Linha desejada
    lineListNode* linha = pegarDoIndexListaSimples(linhas, indiceLinha); //O(n)
    cout << "NUMERO: " << linha->numberLine << endl;
    // Se a linha não possui uma lista de paradas, cria uma nova lista de paradas na linha
    if(linha->parada == nullptr){ // O(1)
        linha->parada = criarListaCircular(); // O(1)
    }
    // Adiciona a nova parada a lista de paradas da linha
    inserirNaListaCircular(linha->parada, nomeParada, saidaParada, chegadaParada); // O(1)
}

//Essa funcao faz a impressao da lista de paradas
/*
A complexidade dessa função no pior caso é O(n) pelo do...while ao percorrer a Lista de Paradas
*/
void ImprimirListaCircular(hourRoundList* list) {
    if (list->firstNode == nullptr) { // O(1)
        std::cout << "A lista de paradas está vazia." << std::endl; // O(1)
        return; // O(1)
    }

    hourRoundNode* currentNode = list->firstNode; // O(1)

    cout << "Horarios de Parada:" << endl; // O(1)
    do{
        cout << "Nome: " << currentNode->nome << ", Saida: " << currentNode->saida << ", Chegada: " << currentNode->chegada << endl; // O(1)
        currentNode = currentNode->next; // O(1)
    }while(currentNode->next != list->firstNode); //O(n)
}

//Ja nessa funcao, ela imprime todas as Linhas de Onibus com suas respectivas paradas
// percorredo a lista de Linhas de Onibus e a cada Linha, imprimindo suas paradas
/*
Por Imprimir as Linhas com suas Paradas, a complexidade desta função no pior caso é O(n*m), onde 
n é a lista de Linhas pelo while e imprimir-lo e m é ao chamar a função de imprimirListaCircular
que como se trata tambem de impressão fica: O(n*m)
*/
void imprimirLinhasComParadas(lineList* linhas){
    if(linhas->size == 0){ // O(1)
        cout << endl << "A lista de linhas esta vazia" << endl; // O(1)
        return; // O(1)
    }
    lineListNode* linhaAtual = linhas->firstNode; // O(1)

    cout << endl << "Lista de Linhas de Onibus com suas respectivas paradas:" << endl; // O(1)

    while(linhaAtual != nullptr){ // O(n)
        cout << "Linha: " << linhaAtual->numberLine << endl << linhaAtual->lineName << endl; // O(1)
        if(linhaAtual->parada != nullptr){ // O(1)
            ImprimirListaCircular(linhaAtual->parada);//O(n)
        } 
        else{
            cout << "Esta linha nao possui paradas atribuidas" << endl; // O(1)
        }

        linhaAtual = linhaAtual->next;  // O(1)
    }
}
//Função da senha para Manutenção do programa
/*
Complexidade O(1) pela operação constante
*/
  bool checkPassword (const std::string & corretPassword, const std::string & userPassword) //Funcao para verificar a senha em caso de manutencao de linhas e paradas
  {
    return corretPassword == userPassword;//O(1)
  }

