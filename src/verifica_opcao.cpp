#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include <algorithm>
#include <set>
#include "../include/verifica_opcao.h"
#include "../include/herois/druida.h"

using namespace std;

Verifica_opcao::Verifica_opcao(unsigned num_opcoes){
    for(unsigned i = 1; i <= num_opcoes; i++)
        _opcoes.insert({i, ""});
}

Verifica_opcao::~Verifica_opcao() {
    _opcoes.clear();
}

bool Verifica_opcao::existe_opcao(unsigned i){
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

unsigned Verifica_opcao::retorna_opcao(){
    std::string op1;
    unsigned op;

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

bool Verifica_opcao::seleciona(unsigned op){
    if(existe_opcao(op)) return true;
    return false;
}

Escolhe_ataque::Escolhe_ataque(Heroi* h):
    Verifica_opcao(h->get_num_habilidades() + 1),
    _heroi(h){
    vector<string> habilidades = h->get_habilidades();

    for(unsigned i = 1; i <= h->get_num_habilidades(); i++)
        _opcoes.at(i) = habilidades.at(i-1);
    _opcoes.at(h->get_num_habilidades()+1) = "Mover";
}

Escolhe_ataque::~Escolhe_ataque() {}

void Escolhe_ataque::mostra_menu(){
    cout << "O que " << _heroi->get_nome() << " devera fazer: \n";
    if(_heroi->get_classe()==MAGO || _heroi->get_classe()==PALADINO) cout<<"Mana atual "<< _heroi->get_mana()<<endl;
    mostra_opcoes();
}

static const char *enum_to_string[] = { 
    "Humano", 
    "Urso", 
    "Lobo", 
    "Falcao" 
};

Escolhe_transformacao_druida::Escolhe_transformacao_druida(Heroi* h):
    Verifica_opcao(3),
    _heroi(h){
    Heroi* heroi = new Druida(h->get_nome(), h->get_vida(), h->get_dano());
    Druida* druida = dynamic_cast<Druida*>(heroi);

    set<string> habilidades = {"Humano", "Falcao", "Lobo", "Urso"};
    habilidades.erase(enum_to_string[druida->get_tranformacao()]);

    int i = 1;
    for(auto h: habilidades){
        _opcoes.at(i) = h;
        i++;
    }
}

Escolhe_transformacao_druida::~Escolhe_transformacao_druida() {}

void Escolhe_transformacao_druida::mostra_menu(){
    cout << "Em que " << _heroi->get_nome() << " se transformará: \n";
    mostra_opcoes();
}


void Escolhe_alvo::mostra_menu(){
    cout << "Em quem: \n";
    mostra_opcoes();
}

Escolhe_alvo::Escolhe_alvo(vector<Personagem *> personagens):
    Verifica_opcao(personagens.size()),
    _personagens(personagens){
    for(unsigned i = 1; i <= personagens.size(); i++)
        _opcoes.at(i) = _personagens.at(i-1)->get_nome();
}

Escolhe_alvo::~Escolhe_alvo() {}

Escolhe_classe::Escolhe_classe(unsigned i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Druida";
    _opcoes.at(2) = "Guerreiro";
    _opcoes.at(3) = "Mago";
    _opcoes.at(4) = "Paladino";
}

Escolhe_classe::~Escolhe_classe() {}

bool Escolhe_classe::seleciona(unsigned op){
    if(existe_opcao(op)){
        _opcoes.erase(op);
        return true;
    }
    return false;
}

void Escolhe_classe::mostra_menu(){
    cout << "Qual sera a classe do heroi?" << endl;
    mostra_opcoes();
}

Escolhe_menu::Escolhe_menu(unsigned i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Novo Jogo";
    _opcoes.at(2) = "Carregar Jogo";
    _opcoes.at(3) = "Créditos";
    _opcoes.at(4) = "Sair";
}

Escolhe_menu::~Escolhe_menu() {}

void Escolhe_menu::mostra_menu(){
    cout << termcolor::green << "JOGO DE RPG MUITO MANEIRO\n\n" << termcolor::reset;
    mostra_opcoes();
}

Escolhe_saida::Escolhe_saida(unsigned i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Sim";
    _opcoes.at(2) = "Não";
}

Escolhe_saida::~Escolhe_saida() {}

void Escolhe_saida::mostra_menu(){
    cout << termcolor::red << "GAME OVER!" << termcolor::reset << endl;
    cout << "Deseja tentar de novo?" << endl;
    mostra_opcoes();
}

Escolhe_salvar::Escolhe_salvar(unsigned i):
    Verifica_opcao(i){
    _opcoes.at(1)="Continuar";
    _opcoes.at(2)="Salvar e continuar";
    _opcoes.at(3)="Salvar e sair";
    _opcoes.at(4)="Sair sem salvar";
}

Escolhe_salvar::~Escolhe_salvar(){}

void Escolhe_salvar::mostra_menu(){
    cout << "O que você deseja fazer?" << endl;
    mostra_opcoes();
}

Escolhe_save::Escolhe_save(unsigned i):
    Verifica_opcao(i) {
    _opcoes.at(1) = "Save 1";
    _opcoes.at(2) = "Save 2";
    _opcoes.at(3) = "Save 3";
}

Escolhe_save::~Escolhe_save(){}

void Escolhe_save::mostra_menu(){
    cout << "\nEm qual save deseja voltar? " << endl;
    mostra_opcoes();
}
