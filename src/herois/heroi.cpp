#include <iostream>
using namespace std;

#include "../../include/herois/heroi.h"

Heroi::Heroi(
    string nome,
    int vida,
    int dano
):  Personagem(nome, vida, dano),
    _exp(0),
    _vida_max(vida) {}

Heroi::~Heroi() {}

int Heroi::get_vida_max(){
    return _vida_max;
}

unsigned int Heroi::get_exp(){
    return _exp;
}

void Heroi::ganha_exp(int exp){
    if(exp < 0) throw impossivel_adicionar_exp_negativa_e();

    _exp += exp;
    while(_exp >= 100){
        aumenta_nivel();
        _exp -= 100;
    }
}

void Heroi::aumenta_nivel(){
    _nivel++;
    _vida += 3;
    _vida_max +=3;
    _dano += 3;

    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
}

void Heroi::recebe_cura(int cura){
    if(cura <= 0) throw cura_negativa_e();
    if(_morto==true) throw nao_pode_curar_morto_e();

    if((_vida_max - _vida)<=cura) _vida = _vida_max;
    else _vida += cura;
}

void Heroi::move(){
    if(_lugar.get_x() < 3) 
        _lugar.set_x(_lugar.get_x()+1);
    else 
        throw posicao_invalida_e();
}
