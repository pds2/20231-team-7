#include "../../include/monstros/cao_infernal.h"
#include <iostream>
#include <string>
using namespace std;

int CaoInfernal::_id = 1;

CaoInfernal::CaoInfernal(): Monstro("Cao_infernal_"+to_string(_id),45,15,30){
    _id++;
}

CaoInfernal::~CaoInfernal(){
}

tamanho CaoInfernal::get_tamanho(){
    return _MEDIO;
}

string CaoInfernal::get_letra(){
    return "C";
}

void CaoInfernal::ataque(int num_ataque, int valor_dado, std::vector<Personagem *> inimigos){
    if(get_nome() == inimigos[0]->get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();

    int alvo = retorna_alvo();
    inimigos.at(alvo)->recebe_dano(calcula_ataque(valor_dado)/2);
}
