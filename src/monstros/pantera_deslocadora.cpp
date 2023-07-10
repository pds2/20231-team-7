#include "../../include/monstros/pantera_deslocadora.h"
#include <iostream>
#include <string>
using namespace std;

int PanteraDeslocadora::_id = 1;

PanteraDeslocadora::PanteraDeslocadora():Monstro("Pantera_deslocadora_"+to_string(_id),85,18,3,13,4){
    _id++;
}

PanteraDeslocadora::~PanteraDeslocadora(){
}

tamanho PanteraDeslocadora::get_tamanho(){
    return _GRANDE;
}

string PanteraDeslocadora::get_letra(){
    return "P";
}

void PanteraDeslocadora::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    
}
