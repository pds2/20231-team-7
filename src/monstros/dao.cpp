#include "../../include/monstros/dao.h"
#include <iostream>
#include <string>
using namespace std;


Dao::Dao()
: Monstro("dao",187,24,11,18,3){
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