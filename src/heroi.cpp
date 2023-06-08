#include <iostream>
using namespace std;

#include "../include/heroi.h"

Heroi::Heroi(
    string nome,
    int vida,
    int vida_max,
    int dano
):  Personagem(nome, vida, dano),
    _vida_max(vida_max),
    _exp(0) {}

Classes Heroi::get_classe() const{
    return Classes::GUERREIRO;
}

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
        _exp = 0;
    }
}

void Heroi::aumenta_nivel(){
    _nivel++;
    _vida += 3;
    _dano += 3;

    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
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
