#include "../../include/monstros/pantera_deslocadora.h"
#include <iostream>
#include <string>
using namespace std;

int PanteraDeslocadora::_id = 1;

PanteraDeslocadora::PanteraDeslocadora():Monstro("Pantera_deslocadora_"+to_string(_id),85,18,60){
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
    if(get_nome() == inimigos[0]->get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();

    for(auto g :inimigos){
        g->recebe_dano(calcula_ataque(valor_dado)/2);
    }
}
