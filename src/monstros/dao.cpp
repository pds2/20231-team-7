#include "../../include/monstros/dao.h"
#include <iostream>
#include <string>
using namespace std;

int Dao::_id = 1;

Dao::Dao(): Monstro("Dao",187,24,11,18,3){
    _id++;
}

Dao::~Dao(){
}

tamanho Dao::get_tamanho(){
    return _GRANDE;
}

habilidade Dao::get_habilidade(){
    return _FORCA;
}

void Dao::ataque(int valor_dado, std::vector<Personagem *> inimigos){

}
