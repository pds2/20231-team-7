#include "../../include/monstros/golem_de_carne.h"
#include <iostream>
#include <string>
using namespace std;

int Golem_de_carne::_id = 1;

Golem_de_carne::Golem_de_carne()
: Monstro("Golem_"+to_string(_id),93,18,80){
    _id++;
}

Golem_de_carne::~Golem_de_carne(){
}

tamanho Golem_de_carne::get_tamanho(){
    return _MEDIO;
}

string Golem_de_carne::get_letra(){
    return "G";
}

void Golem_de_carne::ataque(int num_ataque, int valor_dado, std::vector<Personagem *> inimigos){
    if(get_nome() == inimigos[0]->get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();

    int alvo = retorna_alvo();
    inimigos.at(alvo)->recebe_dano(calcula_ataque(valor_dado)/2);
}
