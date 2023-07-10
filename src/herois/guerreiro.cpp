#include <iostream>
using namespace std;

#include "../../include/herois/guerreiro.h"

Guerreiro::Guerreiro(
    string nome,
    int vida,
    int dano
): Heroi(nome, vida, dano),_furia(false) {
    _ataques.push_back("Investida");
}

Guerreiro::~Guerreiro() {}

Classes Guerreiro::get_classe() const {
    return Classes::GUERREIRO;
}

unsigned Guerreiro::get_num_habilidades(){
    return _ataques.size();
}

string Guerreiro::get_letra(){
    return "G";
}

void Guerreiro::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    for(auto inimigo: inimigos) 
        if(get_nome()==inimigo->get_nome()) throw personagem_ataca_a_si_mesmo_e();    
    if(valor_dado <= 0)
        throw valor_dado_negativo_e();

    for(auto inimigo: inimigos) {
        if(_furia==false) inimigo->recebe_dano(get_dano() + valor_dado);
        if(_furia==true){
            inimigo->recebe_dano((get_dano() + valor_dado)*2);
            _furia=false;
       }
    }
}

void Guerreiro::ativa_furia(){
    if(_furia==true) throw furia_ja_ativa_e();
    else _furia=true;
}

bool Guerreiro::get_furia(){
    return _furia;
}

void Guerreiro::aumenta_nivel(){
    _nivel ++;
    _vida += 3;
    _vida_max += 3;
    _dano += 3;

    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    _ataques.push_back("Furia");

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
}

vector<string> Guerreiro::get_habilidades() {
    return _ataques;
}
