#include <iostream>
using namespace std;

#include "../../include/herois/guerreiro.h"

Guerreiro::Guerreiro(
    string nome,
    int vida,
    int dano
): Heroi(nome, vida, dano) {}

Classes Guerreiro::get_classe() const {
    return Classes::GUERREIRO;
}

void Guerreiro::ataque(Personagem &inimigo, int valor_dado){
    if(get_nome() == inimigo.get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado <= 0)
        throw valor_dado_negativo_e();

    inimigo.recebe_dano(get_dano() + valor_dado);
}
