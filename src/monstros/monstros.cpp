#include "../../include/monstros/monstros.h"
#include "../../include/rolar_dados.h"
using namespace std;

Monstro::Monstro(std::string nome, int vida, int dano,
int exp)
: Personagem(nome, vida, dano),
_exp(exp) {}

Monstro::~Monstro() {}

void Monstro::aumenta_nivel(){
    _vida += 3;
    _dano += 3;
    _nivel++;
}

int Monstro::retorna_alvo(){
    Rolar_Dados d;
    int alvo = d.calcula_dado(2);
    return alvo-1;
}

int Monstro::get_exp(){
    return _exp;
}

bool Monstro::eh_heroi(){
    return false;
}

void Monstro::move(){
    if(_lugar.get_x() > 1) 
        _lugar.set_x(_lugar.get_x()-1);
    else 
        throw posicao_invalida_e();
}
