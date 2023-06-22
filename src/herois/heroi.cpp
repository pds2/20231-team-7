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
    if(exp <= 0) throw impossivel_adicionar_exp_negativa_e();

    _exp += exp;
    if(_exp >= 100){
        aumenta_nivel();
        _exp -= 100;
    }
}

void Heroi::aumenta_nivel(){
    _nivel++;
    _vida += 3;
    _vida_max += 3;
    _dano += 3;

	cout << "Nivel subiu para " << termcolor::green << _nivel << termcolor::reset << endl;
}

void Heroi::recebe_cura(int cura){
    if(cura <= 0) throw cura_negativa_e();
    if(_morto==true) throw nao_pode_curar_morto_e();

    if((_vida_max - _vida)<=cura) _vida = _vida_max;
    else _vida += cura;
}

void Heroi::adiciona_habilidade(string habilidade){
    if(_habilidades.count(habilidade) != 0)
        throw habilidade_ja_existe_e();

    _habilidades.insert(pair<string,bool>(habilidade, false));
}

void Heroi::desbloqueia_habilidade(string habilidade){
    if(_habilidades.count(habilidade) == 0)
        throw habilidade_nao_existe_e();

    _habilidades.at(habilidade) = true;
}

void Heroi::print_habilidades(){
    int i = 0;
    for(auto h: _habilidades){
        if(h.second == true){
            cout << i << " - " << h.first << endl;
            i++;
        }
    }
}
