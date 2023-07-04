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

#include "../include/rolar_dados.h"
using namespace std;

void pausa_tela(){
    #ifdef _WIN32
        system("pause >nul"); // para sistemas Windows
    #else
        system("read -n1 -r -p 'Pressione qualquer tecla para continuar...'"); // para sistemas baseados em Unix
    #endif
}

void mostra_menu(){
    cout << string(50, ' ') << "JOGO DE RPG COM ENIGMAS\n\n";
    cout << "Escolha uma opção para seguir:\n";
    cout << "1. Começar\n";
    cout << "2. Créditos\n";
    cout << "3. Sair\n";
    cout << "> ";

    /* Nova forma
    cout << "1. Novo Jogo\n";
    cout << "2. Carregar Jogo\n";
    cout << "3. Créditos\n";
    cout << "4. Sair\n";
    cout << "> ";
    */
}

void mostra_creditos(){
    system("clear");
    cout << "TRABALHO PRÁTICO DE PDS2\n";
    cout << "JOGO DE RPG COM ENIGMAS\n\n";
    cout << "Por:\n";
    cout << "- Caroline Campos Carvalho\n";
    cout << "- Deborah Brito Yamamoto\n";
    cout << "- Iago Zagnoli Albergaria\n";
    cout << "- Mateus Cursino Gomes Costa\n" << flush;

    system("read -n 1 -s -r -p 'Aperte qualquer tecla para retornar ao menu...'");
}

void mostra_classes(int i){
    cout << "Qual será a classe do herói " << i << "?" << endl;
    cout << "1. Druida\n";
    cout << "2. Guerreiro\n";
    cout << "3. Mago\n";
    cout << "4. Paladino\n";
    cout << "> ";
}

Heroi* instancia_personagem(string nome, int i){
    string op1;
    int op;

    mostra_classes(i);
    while(cin >> op1){
        istringstream is(op1);
        is >> op;

        if(op == 1){
            // START GAME
            Heroi *p = new Druida(nome, 10, 10); 
            return p;
        } else if(op == 2){
            Heroi *p = new Guerreiro(nome, 10, 10); 
            return p;
        } else if(op == 3){
            Heroi *p = new Mago(nome, 10, 10); 
            return p;
        } else if(op == 4){
            Heroi *p = new Paladino(nome, 10, 10); 
            return p;
        } else{
            cout << termcolor::red << "Opção inválida. Tente novamente!\n" << termcolor::reset;
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");
        }

        cout << "\n\n";
        mostra_classes(i);
    }

    Heroi *h = new Druida("",0,0);
    return h;
}

pair<Heroi *,Heroi *> valida_personagens(){
    pair<Heroi *,Heroi *> personagens;

    for(int i = 1; i <= 2; i++){
        string nome;
        do{
            cout << "Qual o nome do herói " << i << "? (max 8 caracteres)" << endl;
            cout << "> ";
            cin >> nome;

            if(nome.size() > 8){
                cout << termcolor::red << "O nome ultrapassa 8 caracteres. Por favor, tente novamente!\n"
                     << termcolor::reset;
                system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");

                system("clear");
            }
        } while(nome.size() > 8);

        
        if(i == 1) 
            personagens.first = instancia_personagem(nome, i);
        else{
            personagens.second = instancia_personagem(nome, i);
            while(personagens.first->get_classe() == personagens.second->get_classe()){
                cout << termcolor::red << "Não é permitido heróis de mesma classe! Tente novamente.\n"
                     << termcolor::reset;
                system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");
                cout << "\n\n";

                personagens.second = instancia_personagem(nome, i);
            }
        }

        cout << endl;
    }
    return personagens;
}

Sistema::Sistema() {}

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
            cout << termcolor::red << "Opção inválida. Tente novamente!\n" << termcolor::reset;
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");
        }

        system("clear");
        mostra_menu();
    }
}

void Sistema::cria_personagens(){
    pair<Heroi *,Heroi *> personagens;

    cout << termcolor::green << "Crie sua equipe:" << termcolor::reset << endl;
    personagens = valida_personagens();

    _herois.set_h1(*personagens.first);
    _herois.set_h2(*personagens.second);
}

void Sistema::inicia_jogo(){
    system("clear");

    Rolar_Dados *dados = new Rolar_Dados();
    bool continua = true;

    cria_personagens();
    Combate *combate = new Combate(_herois);

    Monstro *m1 = new Monstro("goblin", 10, 10, 1, 1, 1);
    Monstro *m2 = new Monstro("goblin2", 10, 10, 1, 1, 1);
    // Monstro *m3 = new Monstro("boss", 10, 10, 1, 1, 1);

    system("read -n 1 -s -r -p 'Aperte qualquer tecla para entrar no combate!'");
    continua = combate->entra_combate({m1, m2});
    
    if(!continua) encerra_jogo();
    else{
        system("clear");
        cout << "ganhou combate." << endl;
    }

    delete combate;
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
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para recomeçar...'");
            inicia_menu(); 
        } else if(op == 0){
            cout << "fraco." << endl;
        } else {
            cout << termcolor::red << "Opção inválida. Tente novamente!\n" << termcolor::reset;
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");
        }
    }
}

void Sistema::salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual){
    if(numslot >3)
        throw slot_invalido_e();
    if(numslot==1){
        ofstream save ("saveslots/save1.txt");
        if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
        save.close();
    }
    if(numslot==2){
        ofstream save("saveslots/save2.txt");
        if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
        save.close();
    }
    if(numslot==3){
        ofstream save("saveslots/save3.txt");
        if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;
        save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_nivel()<<" "<<heroi1.get_exp()<<endl;
        save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_nivel()<<" "<<heroi2.get_exp()<<endl;
        save<<faseatual<<endl;
        save.close();
    }
}

void Sistema::carrega_jogo(unsigned int numslot){
    string linha, nome;
    int classe, vida, nivel, exp, faseatual;
    if(numslot==1){
        ifstream save("saveslots/save1.txt");
        if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;
        for(int i=0;getline(save,linha);i++){
            stringstream str(linha);
            if(i<2){
                str>>nome>>classe>>vida>>nivel>>exp;
                cout<<nome<<" "<<classe<<" "<<vida<<" "<<nivel<<" "<<exp<<endl;
            }
            if(i==2){
                str>>faseatual;
                cout<<faseatual<<endl;
            }
        }
        save.close();
    }
}
