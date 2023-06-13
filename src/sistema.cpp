#include "../include/sistema.h"
#include "../include/druida.h"
#include "../include/rolar_dados.h"

#include <iostream>
using namespace std;

Sistema::Sistema() {}

void Sistema::mostra_menu(){
    cout << string(50, ' ') << "JOGO DE RPG COM ENIGMAS\n\n";
    cout << "Escolha uma opção para seguir:\n";
    cout << "1. Começar\n";
    cout << "2. Créditos\n";
    cout << "3. Sair\n";
    cout << "> ";
}

void Sistema::mostra_creditos(){
    system("clear");
    cout << "TRABALHO PRÁTICO DE PDS2\n";
    cout << "JOGO DE RPG COM ENIGMAS\n\n";
    cout << "Por:\n";
    cout << "- Caroline Campos Carvalho\n";
    cout << "- Deborah Brito Yamamoto\n";
    cout << "- Iago Zagnoli Albergaria\n";
    cout << "- Mateus Cursino Gomes Costa\n" << flush;

    system("read -p 'Aperte ENTER para retornar ao menu...' var");
}

void Sistema::inicia_menu(){
    system("clear");
    mostra_menu();

    while(cin >> _opcao){
        if(_opcao == "1"){
            // START GAME
            inicia_jogo(); 
            break;
        } else if(_opcao == "2"){
            system("clear");
            mostra_creditos();
        } else if(_opcao == "3"){
            exit(0);
        } else{
            cout << "Opção inválida. Tente novamente!\n";
            system("read -p 'Aperte ENTER para continuar...' var");
        }

        system("clear");
        mostra_menu();
    }
}

void Sistema::inicia_jogo(){
    system("clear");

    Rolar_Dados *dados = new Rolar_Dados();

    string nome;
    cout << "Qual o nome do seu jogador?" << endl;
    cin >> nome;

    Heroi *p = new Heroi(nome, 10, 10);
    cout << p->get_nome() << " de nivel " << p->get_nivel() << endl;
    p->ganha_exp(101);
    cout << p->get_nome() << " de nivel " << p->get_nivel() << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d04() << " ";  
    }
    cout << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d06() << " ";  
    }
    cout << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d08() << " ";  
    }
    cout << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d12() << " ";  
    }
    cout << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d20() << " ";  
    }
    cout << endl;

    for(int i = 0; i < 3; i++){
        cout << dados->rolar_d100() << " ";  
    }
    cout << endl;

    cout << "posicao: " << p->get_posicao().get_x() << ", " << p->get_posicao().get_y() << endl;

    delete p;
    delete dados;
}
