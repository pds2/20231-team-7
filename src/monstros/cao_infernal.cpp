#include "../../include/monstros/cao_infernal.h"
#include <iostream>
using namespace std;

CaoInfernal::CaoInfernal(): Monstro("cão infernal",45,15,3,15,2){}

CaoInfernal::~CaoInfernal(){
}

tamanho CaoInfernal::get_tamanho(){
    return _MEDIO;
}

habilidade CaoInfernal::get_habilidade(){
    return _DESTREZA;
}
