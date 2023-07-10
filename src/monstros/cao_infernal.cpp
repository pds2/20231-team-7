#include "../../include/monstros/cao_infernal.h"
#include <iostream>
#include <string>
using namespace std;

int CaoInfernal::_id = 1;

CaoInfernal::CaoInfernal(): Monstro("Cao_infernal_"+to_string(_id),45,15,3,15,2){
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

void CaoInfernal::ataque(int alvo, int valor_dado, std::vector<Personagem *> inimigos){

}
