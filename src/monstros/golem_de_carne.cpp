#include "../../include/monstros/golem_de_carne.h"
#include <iostream>
#include <string>
using namespace std;

int Golem_de_carne::_id = 1;

Golem_de_carne::Golem_de_carne()
: Monstro("Golem_"+to_string(_id),93,18,5,9,1){
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

void Golem_de_carne::ataque(int valor_dado, std::vector<Personagem *> inimigos){

}
