#include "../../include/monstros/pantera_deslocadora.h"
#include <iostream>
using namespace std;

PanteraDeslocadora::PanteraDeslocadora():Monstro("pantera",85,18,3,13,4){}

PanteraDeslocadora::~PanteraDeslocadora(){
}

tamanho PanteraDeslocadora::get_tamanho(){
    return _GRANDE;
}

habilidade PanteraDeslocadora::get_habilidade(){
    return _FORCA;
}

void PanteraDeslocadora::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    
}
