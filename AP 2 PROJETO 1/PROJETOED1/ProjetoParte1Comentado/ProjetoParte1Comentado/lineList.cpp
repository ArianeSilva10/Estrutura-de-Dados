/*
DUPLA:
Raíssa Ívyna Moreira de Oliveira - 553679
Francisca Ariane dos Santos da Silva - 554930
*/

#include "lineList.h"
#include "hourRoundList.h"
using namespace std;


//Funcao que cria uma lista simples de Linhas de Onibus
// Ela aloca memoria para uma instancia de lineList, inicializa
// e retorna um ponteiro para a lista que foi criada
lineList* criarListaSimples(){
    lineList* listHead = new lineList;
    listHead->firstNode = NULL;
    listHead->size = 0;
    return listHead;
}

//Funcao que permite adicionar uma nova Linha de Onibus 
// a lista de Linhas criada criando um novo no de linha
// e inserindo no final da lista
void inserirNaListaSimples(lineList* list ,string lineName){
    //cout << "inserindo Linha" << endl;
    lineListNode* listNode = new lineListNode;
    listNode->lineName = lineName;
    listNode->next = NULL;

    if(list->firstNode == NULL){
        list->firstNode = listNode;
        list->size = 1;
        return;
    }

    lineListNode* lastObject = list->firstNode;
    while (lastObject->next != NULL){
        lastObject = lastObject->next;
    }
    
    lastObject->next = listNode;
    list->size = list->size + 1;
}

//Essa funcao busca por uma Linha de Onibus especifica 
// com base no indice dela, retornando um ponteiro para 
// o no no indice especificado ou nullptr se estiver fora 
// dos limites
lineListNode* pegarDoIndexListaSimples(lineList* list, int index){
    lineListNode* obj = list->firstNode;

    if(obj == NULL){
        return NULL; 
    }

    if(index == 0){
        return obj;
    }
    int ct_index = 0;

    while(ct_index != index && (list != NULL)){
        obj = obj->next;
        ct_index++;
    }

    return obj;
}

//Essa funcao remove uma Linha de Onibus (no) especifico com 
// base no seu indice, liberando memoria alocada para o no de Linha
// e atualiza os ponteiros
void apagarNoIndexListaSimples(lineList* list, int index){
    lineListNode* obj = list->firstNode;
    lineListNode* prev = obj;

    if(obj->next == NULL){
        list->firstNode = NULL;
        delete obj;
        list->size=0;
        return;
    }

    if(index == 0){
        obj = obj->next;
        
        list->firstNode = obj;
        delete prev;
        list->size--;
        return;
    }

    int ct_index = 0;
    
    while(ct_index != index && (list != NULL)){
        prev = obj;
        obj = obj->next;
        ct_index++;
    }

    prev->next = obj->next;
    delete obj;
    list->size--;

}

//Imprime a lista de Linhas de Onibus
void ImprimirListaSimples(lineList* list) {
    lineListNode* currentNode = list->firstNode;

    while (currentNode != nullptr) {
        std::cout << "Linha: " << currentNode->lineName << endl;

        currentNode = currentNode->next;
    }
}

//Funcao que cria uma lista circular de 
// paradas para um Linha de onibus especifica
// aloca memoria para hourRoundList e inicialiaza
hourRoundList* criarListaCircular(){
    hourRoundList* list = new hourRoundList;
    list->firstNode = NULL;
    list->lastNode = NULL;
    list->size = 0;
    return list;
}

//Funcao que adiciona uma nova parada a lista Circular depois de criada
// ela adiciona um novo no de parada e o insere no final da lista
void inserirNaListaCircular(hourRoundList* list, string nome, string saida, string chegada){
    hourRoundNode* node = new hourRoundNode;

    node->chegada = chegada;
    node->nome = nome;
    node->saida = saida;

    if(list->firstNode == NULL){
        node->next = node;
        list->firstNode = node;
        list->lastNode = node;
        node->prev = node;
    }else{
        list->lastNode->next = node;
        list->firstNode->prev = node;
        node->prev = list->lastNode;
        node->next = list->firstNode;

        list->lastNode = node;
    }
    list->size ++;
}

//Funcao que remove uma parada especifica em uma Linha de Onibus
//Ela faz a busca com base no nome da parada e a remove da lista Circular
void removerParada(lineList* lista, int indiceLinha, const std::string& nomeParada){
    lineListNode* linha = pegarDoIndexListaSimples(lista, indiceLinha);
    
    if(linha != nullptr){
        hourRoundList* paradas = linha->parada;

        if(paradas != nullptr){
            hourRoundNode* paradaAtual = paradas->firstNode;
            hourRoundNode* paradaAnterior = nullptr;

            while (paradaAtual != nullptr)
            {
                if(paradaAtual->nome == nomeParada){
                    if(paradaAnterior == nullptr){
                        paradas->firstNode = paradaAtual->next;
                        delete paradaAtual;
                        paradas->size--;
                        cout << "Parada removida da linha " << linha->lineName << endl;
                        return;
                    }
                    else{
                        paradaAnterior->next = paradaAtual->next;
                        delete paradaAtual;
                        paradas->size--;
                        cout << "Parada removida da linha " << linha->lineName << endl;
                        return;
                    }
                }
                paradaAnterior = paradaAtual;
                paradaAtual = paradaAtual->next;
            }
            //se chegou ate aqui eh porque a parada nao foi encontrada
            cout << "Parada nao encontrada na Linha " << linha->lineName << endl;
        }
        //Caso em que a linha esteja vazia, sem paradas
        else{
            cout << "A Linha " << linha->lineName << " nao possui paradas" << endl;
        }
    }
    //Situacao em que nao encontra a linha a qual deseja remover a parada
    else{
        cout << "Linha nao encontrada na posicao: " << indiceLinha << endl;
    }
}

//Funcao que altera os dados de uma parada especifica em uma Linha de Onibus
// Ela faz a busca com base no nome da parada e apos isso atualiza seus dados
void alterarParada(lineList* lista, int indiceLinha, const std::string& nomeParada, const std::string& novoNome, const std::string& novaSaida, const std::string& novaChegada) {
    lineListNode* linha = pegarDoIndexListaSimples(lista, indiceLinha);

    if (linha != nullptr) {
        hourRoundList* paradas = linha->parada;

        if (paradas != nullptr) {
            hourRoundNode* paradaAtual = paradas->firstNode;

            while (paradaAtual != nullptr) {
                //alteracao dos dados no looping
                if (paradaAtual->nome == nomeParada) {
                    paradaAtual->nome = novoNome;
                    paradaAtual->saida = novaSaida;
                    paradaAtual->chegada = novaChegada;
                    cout << "Dados da parada alterados com sucesso na Linha " << linha->lineName << endl;
                    return;
                }
                paradaAtual = paradaAtual->next;
            }
            // Se chegou até aqui, a parada não foi encontrada
            cout << "Parada não encontrada na Linha " << linha->lineName << endl;
        }
        //caso em que a linha não possua paradas
        else {
            cout << "A Linha " << linha->lineName << " não possui paradas" << endl;
        }
    }
    // Situação em que não encontra a linha a qual deseja alterar a parada
    else {
        cout << "Linha não encontrada na posição: " << indiceLinha << endl;
    }
}

//Funcao que permite adicionar uma nova parada a uma Linha de Onibus especifica
// Criando um novo no de parada e adicionando a lista Circular de paradas
void atribuirParadaEmLinha(lineList* linhas, int indiceLinha, std::string nomeParada, std::string saidaParada, std::string chegadaParada){
    if(indiceLinha < 0 || indiceLinha >= linhas->size){
        std::cout << "Indice de linha invalido." << std::endl;
        return;
    }
    // Cria uma nova parada
    hourRoundNode* novaParada = new hourRoundNode();
    novaParada->nome = nomeParada;
    novaParada->saida = saidaParada;
    novaParada->chegada = chegadaParada;
    novaParada->next = nullptr;

    // Linha desejada
    lineListNode* linha = pegarDoIndexListaSimples(linhas, indiceLinha);

    // Se a linha não possui uma lista de paradas, cria uma nova lista de paradas na linha
    if(linha->parada == nullptr){
        linha->parada = criarListaCircular();
    }
    // Adiciona a nova parada a lista de paradas da linha
    inserirNaListaCircular(linha->parada, nomeParada, saidaParada, chegadaParada);
    //std::cout << "Parada inserida na linha." << std::endl;
}

//Essa funcao faz a impressao da lista de paradas
void ImprimirListaCircular(hourRoundList* list) {
    if (list->firstNode == nullptr) {
        std::cout << "A lista de paradas está vazia." << std::endl;
        return;
    }

    hourRoundNode* currentNode = list->firstNode;

    cout << "Horarios de Parada:" << endl;
    do{
        cout << "Nome: " << currentNode->nome << ", Saida: " << currentNode->saida << ", Chegada: " << currentNode->chegada << endl;
        currentNode = currentNode->next;
    }while(currentNode->next != list->firstNode);
}

//Ja nessa funcao, ela imprime todas as Linhas de Onibus com suas respectivas paradas
// percorredo a lista de Linhas de Onibus e a cada Linha, imprimindo suas paradas
void imprimirLinhasComParadas(lineList* linhas){
    if(linhas->size == 0){
        cout << endl << "A lista de linhas esta vazia" << endl;
        return;
    }
    lineListNode* linhaAtual = linhas->firstNode;

    cout << endl << "Lista de Linhas de Onibus com suas respectivas paradas:" << endl;

    while(linhaAtual != nullptr){
        cout << "Linha: " << linhaAtual->lineName << endl;
        if(linhaAtual->parada != nullptr){
            ImprimirListaCircular(linhaAtual->parada);
        } 
        else{
            cout << "Esta linha nao possui paradas atribuidas" << endl;
        }

        linhaAtual = linhaAtual->next; 
    }
}

int main(){

    lineList* linhaOnibus = criarListaSimples();

    inserirNaListaSimples(linhaOnibus , "Guanabara(For/Pacajus)");
    inserirNaListaSimples(linhaOnibus,"Guanabara(For/Pacajus)");
    inserirNaListaSimples(linhaOnibus, "Sao_Benedito(For/Canoa)");
    inserirNaListaSimples(linhaOnibus, "Sao_Benedito(For/Canoa)");
    inserirNaListaSimples(linhaOnibus, "Sao_Benedito(For/Pedras)");

    //imprimindo apos a inserção
    //std::cout << endl << "Lista de Linhas de Onibus:" << endl;
    //ImprimirListaSimples(linhaOnibus);

    //testando a função pegarDoIndexListaSimples
    int LinhaDesejada = 1;
    lineListNode* obj = pegarDoIndexListaSimples(linhaOnibus, LinhaDesejada);
    if(obj != nullptr){
        //std::cout << endl << "Linha na posicao especifica: " << obj->lineName << endl;
    }
    else{
        //std::cout << endl <<  "Linha nao encontrada na posicao especificada." << endl;
    }

    //testando a funcao apagarNoIndexListaSimples
    apagarNoIndexListaSimples(linhaOnibus, LinhaDesejada);
    //std::cout << endl << "Lista de Linhas apos remover uma especifica: " << endl;
    //imprimindo apos a remocao
    //ImprimirListaSimples(linhaOnibus);
    //std::cout << "Numero de Linhas: " << linhaOnibus->size << endl;


    hourRoundList* paradas = criarListaCircular();

    inserirNaListaCircular(paradas, "Fortaleza", "18:00", "13:50");
    inserirNaListaCircular(paradas, "Messejana", "14:30", "14:45");
    inserirNaListaCircular(paradas, "Pacajus", "16:00", "16:10");

    //teste para paradas apos a insercao
    //cout << endl << "Paradas apos a insercao: " <<  endl;
    //ImprimirListaCircular(paradas);



    atribuirParadaEmLinha(linhaOnibus, 0, "Fortaleza", "13:50", "18:00");
    atribuirParadaEmLinha(linhaOnibus, 0, "Messejana", "14:30", "14:45");
    atribuirParadaEmLinha(linhaOnibus, 0, "Pacajus", "16:00", "16:10");
    atribuirParadaEmLinha(linhaOnibus, 0, "Messejana", "17:15", "17:25");

    atribuirParadaEmLinha(linhaOnibus, 1, "Fortaleza", "7:00", "11:10");
    atribuirParadaEmLinha(linhaOnibus, 1, "Messejana", "7:40", "7:55");
    atribuirParadaEmLinha(linhaOnibus, 1, "Pacajus", "9:10", "9:20");
    atribuirParadaEmLinha(linhaOnibus, 1, "Messejana", "10:25", "10:35");

    atribuirParadaEmLinha(linhaOnibus, 2, "Fortaleza", "7:00", "12:30");
    atribuirParadaEmLinha(linhaOnibus, 2, "Cascavel", "8:10", "8:20");
    atribuirParadaEmLinha(linhaOnibus, 2, "CanoaQuebrada", "9:30", "10:00");
    atribuirParadaEmLinha(linhaOnibus, 2, "Cascavel", "11:10", "11:20");

    atribuirParadaEmLinha(linhaOnibus, 3, "Fortaleza", "13:50", "18:00");
    atribuirParadaEmLinha(linhaOnibus, 3, "Cascavel", "14:30", "14:45");
    atribuirParadaEmLinha(linhaOnibus, 3, "CanoaQuebrada", "16:00", "16:10");
    atribuirParadaEmLinha(linhaOnibus, 3, "Cascavel", "17:15", "17:25");

    
    imprimirLinhasComParadas(linhaOnibus);



    //testando a funcao removerParada
    removerParada(linhaOnibus, 2, "Fortaleza");
    std::cout << endl << "Paradas apos a remocao: " <<  endl;
    imprimirLinhasComParadas(linhaOnibus);
    
    //testando a funcao alterarParada
    int LinhaDaParadaDesejada = 1;

    string nomeAntigo = "Pacajus", novoNome = "Quixada", NovaSaida = "9:20", NovaChegada = "11:00";
    cout << endl << "Paradas apos a alteracao na posicao " << LinhaDaParadaDesejada << endl;
    alterarParada(linhaOnibus, LinhaDaParadaDesejada, nomeAntigo, novoNome, NovaSaida, NovaChegada);

    imprimirLinhasComParadas(linhaOnibus);

}