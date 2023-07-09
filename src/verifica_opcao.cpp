#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include <algorithm>
#include "../include/verifica_opcao.h"

using namespace std;

Verifica_opcao::Verifica_opcao(int num_opcoes){
    for(int i = 1; i <= num_opcoes; i++)
        _opcoes.insert({i, ""});
}

Verifica_opcao::~Verifica_opcao() {
    _opcoes.clear();
}

bool Verifica_opcao::existe_opcao(int i){
    return(_opcoes.count(i) > 0);
}

void Verifica_opcao::mostra_opcoes(){
    for(auto op: _opcoes)
        cout << op.first << " - " << op.second << endl;

    cout << "> ";
}

void Verifica_opcao::mostra_menu(){
    mostra_opcoes();
}

int Verifica_opcao::retorna_opcao(){
    std::string op1;
    int op;

    mostra_menu();
    while(cin >> op1){
        istringstream is(op1);
        is >> op;
        
        if(seleciona(op)) return op;

        cout << termcolor::red << "Opção inválida. Tente novamente!\n" << termcolor::reset;
        system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");

        system("clear");
        mostra_menu();
    }

    return op;
}

bool Verifica_opcao::seleciona(int op){
    if(existe_opcao(op)) return true;
    return false;
}

Escolhe_classe::Escolhe_classe(int i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Druida";
    _opcoes.at(2) = "Guerreiro";
    _opcoes.at(3) = "Mago";
    _opcoes.at(4) = "Paladino";
}

Escolhe_classe::~Escolhe_classe() {}

bool Escolhe_classe::seleciona(int op){
    if(existe_opcao(op)){
        _opcoes.erase(op);
        return true;
    }
    return false;
}

Escolhe_menu::Escolhe_menu(int i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Novo Jogo";
    _opcoes.at(2) = "Carregar Jogo";
    _opcoes.at(3) = "Créditos";
    _opcoes.at(4) = "Sair";
}

Escolhe_menu::~Escolhe_menu() {}

void Escolhe_menu::mostra_menu(){
    cout << termcolor::green << "JOGO DE RPG COM ENIGMAS\n\n" << termcolor::reset;
    mostra_opcoes();
}

Escolhe_saida::Escolhe_saida(int i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Sim";
    _opcoes.at(2) = "Não";
}

Escolhe_saida::~Escolhe_saida() {}

void Escolhe_saida::mostra_menu(){
    cout << "Deseja tentar de novo?" << endl;
    mostra_opcoes();
}


Escolhe_save::Escolhe_save(int i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Save 1";
    _opcoes.at(2) = "Save 2";
    _opcoes.at(3) = "Save 3";
}

Escolhe_save::~Escolhe_save() {}
