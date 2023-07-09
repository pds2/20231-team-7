#include "../include/sistema.h"
#include "../include/herois/mago/mago.h"
#include "../include/herois/guerreiro.h"
#include "../include/herois/druida.h"
#include "../include/herois/paladino.h"
#include "../include/monstros/cao_infernal.h"
#include "../include/monstros/pantera_deslocadora.h"
#include "../include/rolar_dados.h"
#include "../include/combate.h"
#include "../include/verifica_opcao.h"

#include <thread>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
using namespace chrono;

void texto_credito(){
    system("clear");
    cout << "TRABALHO PRÁTICO DE PDS2\n";
    cout << "JOGO DE RPG COM ENIGMAS\n\n";
    cout << "Por:\n";
    cout << "- Caroline Campos Carvalho\n";
    cout << "- Deborah Brito Yamamoto\n";
    cout << "- Iago Zagnoli Albergaria\n";
    cout << "- Mateus Cursino Gomes Costa\n\n";
}

void mostra_creditos(){
    for(int i = 5; i > 0; i--){
        texto_credito();
        cout << "Voltando para o menu em " << i << "...";
        cout.flush();
        this_thread::sleep_for(1s); 
    }
}

Heroi* instancia_personagem(string nome, int op){
    switch(op) {
        case 1:{
            Heroi *p = new Druida(nome, 10, 10); 
            return p;
        }
        case 2:{
            Heroi *p = new Guerreiro(nome, 10, 10); 
            return p;
        }
        case 3:{
            Heroi *p = new Mago(nome, 10, 10); 
            return p;
        }
        case 4:{
            Heroi *p = new Paladino(nome, 10, 10); 
            return p;
        }
        default:{
            Heroi *p = new Druida("",0,0);
            return p; 
        }
    }
}

string valida_nome(int i){
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

    return nome;
}

pair<Heroi *,Heroi *> valida_personagens(){
    pair<Heroi *,Heroi *> personagens;

    Verifica_opcao *e = new Escolhe_classe(4);
    for(int i = 1; i <= 2; i++){
        string nome = valida_nome(i);

        cout << "Qual será a classe do herói " << i << "?" << endl;
        int op = e->retorna_opcao();

        (i == 1) ? personagens.first = instancia_personagem(nome, op) :
                   personagens.second = instancia_personagem(nome, op);

        cout << endl;
    }

    return personagens;
}

Sistema::Sistema() {}

void Sistema::inicia_menu(){
    system("clear");

    Escolhe_menu e(4);
    int op = e.retorna_opcao();

    switch(op) {
        case 1:{
            inicia_jogo(); 
            break;
        }
        case 2:{
            carrega_jogo(1);
            break;
        }
        case 3:{
            mostra_creditos();
            inicia_menu();
        }
        case 4:{
            exit(0);
        }
    }
}

void Sistema::cria_personagens(){
    pair<Heroi *,Heroi *> personagens;

    system("clear");
    cout << termcolor::green << "Crie sua equipe:" << termcolor::reset << endl;
    personagens = valida_personagens();

    _herois.set_h1(*personagens.first);
    _herois.set_h2(*personagens.second);
}

void Sistema::roda_jogo(){
    Rolar_Dados *dados = new Rolar_Dados();
    bool continua = true;

    Combate *combate = new Combate(_herois);

    Monstro *m1 = new CaoInfernal();
    Monstro *m2 = new CaoInfernal();
    Monstro *m3 = new PanteraDeslocadora();

    system("read -n 1 -s -r -p 'Aperte qualquer tecla para entrar no combate!'");
    continua = combate->entra_combate({m1, m2, m3});
    
    if(!continua) encerra_jogo();
    else{
        system("clear");
        cout << "ganhou combate." << endl;
    }

    delete combate;
    delete dados;
}

void Sistema::inicia_jogo(){
    cria_personagens();

    roda_jogo();
}

void Sistema::encerra_jogo(){
    system("clear");

    cout << termcolor::red << "GAME OVER!" << termcolor::reset << endl;
    cout << "Deseja tentar de novo?" << endl;

    Escolhe_saida e(2);
    int op = e.retorna_opcao();

    switch(op) {
        case 1:{
            cout << "Agora vê se faz direito." << endl;
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para recomeçar...'");
            inicia_menu();
        }
        case 2:{
            cout << "fraco." << endl;
            exit(0);
        }
    }
}

void save(int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual){
    string val= to_string(numslot);
    string saveslot="saveslots/save" + val + ".txt";
    ofstream save (saveslot);
    if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;

    save<<heroi1.get_nome()<< " "<<heroi1.get_classe()<<" "<<heroi1.get_vida()<<" "<<heroi1.get_nivel()<<" "
        <<heroi1.get_exp()<<endl;
    save<<heroi2.get_nome()<< " "<<heroi2.get_classe()<<" "<<heroi2.get_vida()<<" "<<heroi2.get_nivel()<<" "
        <<heroi2.get_exp()<<endl;
    save<<faseatual<<endl;
        save.close();
}

void Sistema::salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual){
    if(numslot > 3)
        throw slot_invalido_e();
    save(numslot,heroi1, heroi2, faseatual);
}

void Sistema::carrega_save(unsigned int numslot){
    string val= to_string(numslot);
    string saveslot="saveslots/save" + val + ".txt";
    string linha, nome;
    int classe, vida, nivel, exp, faseatual;
    pair<Heroi *,Heroi *> personagens;
        ifstream save(saveslot);
        if(!save.is_open()) std::cout<<"Save nao foi aberto corretamente"<<std::endl;
        for(int i=0;getline(save,linha);i++){
            stringstream str(linha);
            if(i<2){
                str>>nome>>classe>>vida>>nivel>>exp;
                if(i == 0){
                    personagens.first = instancia_personagem(nome, classe);
                    personagens.first->ganha_exp(exp+100*(nivel-1));
                    personagens.first->recebe_dano(personagens.first->get_vida_max()-vida);
                } 
                if(i == 1){
                    personagens.second = instancia_personagem(nome, classe);
                    personagens.second->ganha_exp(exp+100*(nivel-1));
                    personagens.second->recebe_dano(personagens.first->get_vida_max()-vida);
                } 
            }
            if(i==2){
                str>>faseatual;
                cout<<faseatual<<endl;//subistituir pra carregamento de fase
            }
        }
        save.close();
    _herois.set_h1(*personagens.first);
    _herois.set_h2(*personagens.second);
        
    }

void Sistema::carrega_jogo(unsigned int numslot){
    carrega_save(numslot);

    roda_jogo();
}
