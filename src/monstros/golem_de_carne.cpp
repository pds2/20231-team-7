#include "../../include/monstros/golem_de_carne.h"
#include <iostream>
#include <string>
using namespace std;



Golem_de_carne::Golem_de_carne()
: Monstro("golem_de_carne",93,18,5,9,1){

}

Golem_de_carne::~Golem_de_carne(){
}

tamanho Golem_de_carne::get_tamanho(){
    return _MEDIO;
}

habilidade Golem_de_carne::get_habilidade(){
    return _FORCA;
}

void Golem_de_carne::ataque(int valor_dado, std::vector<Personagem *> inimigos){

}