#include "../../include/monstros/dao.h"
#include <iostream>
#include <string>
using namespace std;

int Dao::_id = 1;

Dao::Dao(): Monstro("Dao",187,24,150){
    _id++;
}

Dao::~Dao(){
}

tamanho Dao::get_tamanho(){
    return _GRANDE;
}

string Dao::get_letra(){
    return "D";
}

void Dao::ataque(int num_ataque, int valor_dado, std::vector<Personagem *> inimigos){
    if(get_nome() == inimigos[0]->get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();

    for(auto g: inimigos){
        g->recebe_dano(calcula_ataque(valor_dado)/2);
    }
}
