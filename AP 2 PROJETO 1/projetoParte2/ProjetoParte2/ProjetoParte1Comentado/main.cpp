/*
DUPLA:
Raíssa Ívyna Moreira de Oliveira - 553679
Francisca Ariane dos Santos da Silva - 554930
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "lineList.h"
#include "hourRoundList.h"
using namespace std;

void lerArquivo() {
    ifstream arquivo("entrada.txt");
    if(arquivo.is_open()) {
        string linha;
        while(getline(arquivo, linha)) {
            cout << linha << endl;
        }
    }
}

void addArquivoLinha(lineListNode* linha) {
    ofstream arquivo("entrada.txt", ios::app);
    if(arquivo.is_open()){
        int numero = linha->numberLine;
        arquivo << numero;
        string cia = linha->lineName;
        arquivo << "\n";
        arquivo << cia;
        arquivo << "\n$\n";

    }
}
void addArquivoParada(const string& nomeParada, const string& chegadaParada, const string& saidaParada){
    stringstream ss;
    
    
    ofstream arquivo("entrada.txt", ios::app);

    if(arquivo.is_open()){
        arquivo << nomeParada;
        arquivo << " ; ";
        arquivo << chegadaParada;
        arquivo << " ; ";
        arquivo << saidaParada;
        arquivo << "\n";
    }
}

int main() {
    /*lerArquivo();
    addArquivo(nullptr);    
    lerArquivo();*/

    lineList* linhas = criarListaSimples();
    int opcao;
    bool usuarioRegistrado = true;
    while (true) {
        cout << "Menu de Opcoes:" << endl;
        cout << "(1) Procurar Linha de Onibus" << endl;
        if (usuarioRegistrado) {
            cout << "(2) Manutencao do Programa" << endl;
        }
        cout << "Escolha uma opcao: \n";
        cin >> opcao;

        if (opcao == 1) {
            // função para buscar linhas de ônibus aqui
            if (opcao == 1) {
                int numeroLinha;
                cout << "Digite o numero da Linha de Onibus que deseja procurar: ";
                cin >> numeroLinha;
                int posicao = BuscaLinha(linhas, numeroLinha);
                pegarDoIndexListaSimples(linhas, posicao);
                ImprimirListaSimples(linhas);
        }

        } else if (opcao == 2 && usuarioRegistrado) {
            // Precisa da senha para manutenção do sistema
            string corretPassword = "31016"; // Defina sua senha correta aqui
            string userPassword;
            cout << "Digite a senha de 5 digitos: \n";
            cin >> userPassword;

            // Verifique a senha
            if (checkPassword(corretPassword, userPassword)) {
                int opcaoManutencao;
                cout << "Menu de Manutencao:" << endl;
                cout << "(1) Incluir uma nova linha" << endl;
                cout << "(2) Incluir uma parada numa linha" << endl;
                cout << "(3) Alterar uma parada" << endl;
                cout << "(4) Eliminar uma parada" << endl;
                cout << "(5) Eliminar uma linha" << endl;
                cout << "Escolha uma opcao de manutencao: ";
                cin >> opcaoManutencao;

                string nomeLinha;
                int indiceLinha;
                int indexLinha;
                string nomeAntigoParada;
                string nomeParada, chegadaParada, saidaParada;
                string novoNomeParada, novoChegadaParada, novoSaidaParada;
                int linhaIndex;
                string nomeParaRemover;
                int linhaParaRemover;

                switch (opcaoManutencao) {
                    case 1:
                        {// Opção 1: Incluir uma nova linha
                        cout << "Insira o nome da Linha que deseja adicionar: \n";
                        cin >> nomeLinha;
                        cout << "Insira o numero da Linha que deseja adicionar: \n";
                        int numerolinha;
                        cin >> numerolinha;
                        lineListNode* novaLinha = new lineListNode;
                        novaLinha->lineName = nomeLinha;
                        novaLinha->numberLine = numerolinha;

                        inserirNaListaSimples(linhas, nomeLinha, numerolinha);

                        addArquivoLinha(novaLinha);
                        cout << "Linha Inserida com sucesso!\n";
                        lerArquivo();
                        }
                        break;

                    case 2:
                        // Opção 2: Incluir uma parada numa linha
                        cout << "Digite em qual Linha deseja adicionar uma parada:" << endl;
                        cout << "Numero da Linha: ";
                        int linhaNumero;
                        cin >> linhaNumero;
                        cout << "Digite o nome da Parada: ";
                        cin >> nomeParada;
                        cout << "Horario de chegada da parada: ";
                        cin >> chegadaParada;
                        cout << "Horario de saida: ";
                        cin >> saidaParada;
                        indiceLinha = BuscaLinha(linhas, linhaNumero);
                        atribuirParadaEmLinha(linhas, indiceLinha, nomeParada, saidaParada, chegadaParada);
                        addArquivoParada(nomeParada, chegadaParada, saidaParada);
                        lerArquivo();
                        cout << "Parada incluida com sucesso!\n";
                        break;

                    case 3:
                        // Opção 3: Alterar uma parada
                        cout << "Digite a linha na qual deseja alterar a parada:" << endl;
                        cout << "Número da Linha: ";
                        cin >> indexLinha;
                        cout << "Digite o nome da Parada a ser alterada: ";
                        cin >> nomeAntigoParada;
                        cout << "Digite os novos dados da Parada:" << endl;
                        cout << "Novo nome da Parada: ";
                        cin >> novoNomeParada;
                        cout << "Novo horário de chegada da Parada: ";
                        cin >> novoChegadaParada;
                        cout << "Novo horário de saída da Parada: ";
                        cin >> novoSaidaParada;
                        alterarParada(linhas, indexLinha, nomeAntigoParada, novoNomeParada, novoSaidaParada, novoChegadaParada);
                        lerArquivo();
                        cout << "Parada alterada com sucesso!\n";
                        break;

                    case 4:
                        // Opção 4: Eliminar uma parada
                        cout << "Digite a linha da qual deseja remover a parada:" << endl;
                        cout << "Número da Linha: ";
                        cin >> linhaIndex;
                        cout << "Digite o nome da Parada a ser removida: ";
                        cin >> nomeParaRemover;
                        removerParada(linhas, linhaIndex, nomeParaRemover);
                        lerArquivo();
                        cout << "Parada removida com sucesso!\n";
                        break;

                    case 5:
                        // Opção 5: Eliminar uma linha
                        cout << "Digite o número da Linha que deseja remover: ";
                        cin >> linhaParaRemover;
                        apagarNoIndexListaSimples(linhas, linhaParaRemover);
                        lerArquivo();
                        cout << "Linha removida com sucesso!\n";
                        break;

                    default:
                        cout << "Opcao de manutencao invalida." << endl;
                }
            } 
            else {
                cout << "Senha incorreta. Seu acesso foi negado." << endl;
            }
        } 
        else {
            cout << "Opcao invalida. Escolha opcoes de 1 a 5." << endl;
        }
    }
}
