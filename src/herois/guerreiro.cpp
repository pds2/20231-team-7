#include <iostream>
using namespace std;

#include "../../include/herois/guerreiro.h"

Guerreiro::Guerreiro(
    string nome,
    int vida,
    int dano
): Heroi(nome, vida, dano) {
    _ataques.insert("Investida");
}

Classes Guerreiro::get_classe() const {
    return Classes::GUERREIRO;
}

void Guerreiro::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    for(auto inimigo: inimigos) 
        if(get_nome()==inimigo->get_nome()) throw personagem_ataca_a_si_mesmo_e();    
    if(valor_dado <= 0)
        throw valor_dado_negativo_e();

    for(auto inimigo: inimigos) 
        inimigo->recebe_dano(get_dano() + valor_dado);
}

void Guerreiro::aumenta_nivel(){
    _nivel ++;
    _vida += 3;
    _vida_max += 3;
    _dano += 3;

    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    _ataques.insert("furia");

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
}

void Guerreiro::print_habilidades(){
    int i = 1;
    for(auto ataque : _ataques){
        cout << i << " - " << ataque << endl;
    }
}