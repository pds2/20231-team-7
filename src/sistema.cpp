#include "../include/sistema.h"
#include "../include/herois/mago/mago.h"
#include "../include/herois/guerreiro.h"
#include "../include/herois/druida.h"
#include "../include/herois/paladino.h"
#include "../include/rolar_dados.h"
#include "../include/combate.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

pair<string,string> valida_nome(){
    pair<string,string> nomes;

    for(int i = 1; i <= 2; i++){
        string nome;
        do{
            cout << "Qual o nome do jogador " << i << "? (max 8 caracteres)" << endl;
            cin >> nome;

            if(i == 1) nomes.first = nome;
            else nomes.second = nome;

            if(nome.size() > 8){
                cout << "O nome ultrapassa 8 caracteres. Por favor, tente novamente!\n";
                system("read -p 'Aperte ENTER para continuar...' var");

                system("clear");
            }
        } while(nome.size() > 8);
    }
    return nomes;
}

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

    int op;
    while(cin >> _opcao){
        istringstream is(_opcao);
        is >> op;

        if(op == 1){
            // START GAME
            inicia_jogo(); 
            break;
        } else if(op == 2){
            system("clear");
            mostra_creditos();
        } else if(op == 3){
            exit(0);
        } else{
            cout << "Opção inválida. Tente novamente!\n";
            system("read -p 'Aperte ENTER para continuar...' var");
        }

        system("clear");
        mostra_menu();
    }
}

void Sistema::cria_personagens(){
    pair<string,string> nomes;
    nomes = valida_nome();

    Mago *p = new Mago(nomes.first, 9, 10);
    Druida *d = new Druida(nomes.second, 7, 10); 

    _herois.set_h1(*p);
    _herois.set_h2(*d);
}

void Sistema::inicia_jogo(){
    system("clear");

    Rolar_Dados *dados = new Rolar_Dados();
    Combate combate;
    bool continua = true;

    cria_personagens();

    Monstro *m1 = new Monstro("goblin", 10, 10, 1, 1, 1);
    Monstro *m2 = new Monstro("goblin2", 10, 10, 1, 1, 1);

    system("read -p 'Aperte ENTER para entrar no combate!' var");
    continua = combate.entra_combate(_herois, *m1, *m2);
    
    if(!continua) encerra_jogo();
    delete m1;
    delete m2;
    delete dados;
}

void Sistema::encerra_jogo(){
    system("clear");

    cout << termcolor::red << "GAME OVER SEU OTARIO!" << termcolor::reset << endl;

    cout << "Deseja tentar de novo? (1 - Sim, 0 - Não)" << endl;
    cout << "> ";

    int op;
    while(cin >> _opcao){
        istringstream is(_opcao);
        is >> op;

        if(op == 1){
            // RESTART GAME
            cout << "Agora vê se faz direito." << endl;
            system("read -p 'Aperte ENTER para recomeçar...' var");
            inicia_menu(); 
        } else if(op == 0){
            cout << "fraco." << endl;
            exit(0);
        } else {
            cout << "Opção inválida. Tente novamente!\n";
            system("read -p 'Aperte ENTER para continuar...' var");
        }
    }
}

void Sistema::salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual){
    if(numslot >3)throw slot_invalido_e();
    if(numslot==1){
        ofstream save("../saveslots/save1.txt",ios::trunc);
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida_max()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_dano()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida_max()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_dano()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
    }
    if(numslot==2){
        ofstream save("../saveslots/save2.txt",ios::trunc);
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida_max()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_dano()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida_max()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_dano()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
    }
    if(numslot==3){
        ofstream save("../saveslots/save3.txt",ios::trunc);
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida_max()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_dano()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida_max()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_dano()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
    }
}

void Sistema::carrega_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual){

}
