#include "../../include/monstros/monstros.h"

using namespace std;

Monstro::Monstro(std::string nome, int vida, int dano,
int nivel_de_desafio, int classe_de_armadura,
int valor_nivel_minimo): Personagem(nome, vida, dano),_nivel_de_desafio
(nivel_de_desafio),_classe_de_armadura(classe_de_armadura),
_valor_nivel_minimo(valor_nivel_minimo) {}

Monstro::~Monstro() {}

void Monstro::aumenta_nivel(){
    _vida += 3;
    _dano += 3;
    _nivel_de_desafio++;
}

bool Monstro::eh_heroi(){
    return false;
}
