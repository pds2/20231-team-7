#include <iostream>
using namespace std;

#include "../../include/herois/druida.h"

   Druida::Druida(
    string nome,
    int vida,
    int dano
):  Heroi(nome, vida, dano),
     _trans(Humano){}

    
Classes Druida::get_classe() const{
    return Classes::DRUIDA;
}

Tranformacao Druida::get_tranformacao(){
    return _trans;
}

void Druida::transformar(Tranformacao trans){
    if(_trans==trans) 
        throw nao_pode_transformar_para_transformacao_atual_e();
    
    if(_trans==Urso) _vida=_vida-5;
    if(_trans==Lobo) _vida=_vida-3;
    if(_trans==Falcao) _vida--;

    if(trans==Urso) _vida=_vida+5;
    if(trans==Lobo) _vida=_vida+3;
    if(trans==Falcao) _vida++;

    _trans= trans;
    if(_vida<=0) _vida=1;
}

void Druida::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    if(get_nome() == inimigo1.get_nome()||get_nome() == inimigo2.get_nome()||get_nome() == inimigo3.get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();
    if(get_tranformacao()==Humano){
        if(valor_dado == 1) inimigo1.recebe_dano(get_dano() - 3);
        if(valor_dado == 2) inimigo1.recebe_dano(get_dano() - 2);
        else if(valor_dado == 3) inimigo1.recebe_dano(get_dano());
        else inimigo1.recebe_dano(get_dano() + (valor_dado / 2));
    }
    if(get_tranformacao()==Falcao){
        if(valor_dado == 1) {
            inimigo1.recebe_dano(get_dano() - 3);
            inimigo2.recebe_dano(get_dano() - 3);
            inimigo3.recebe_dano(get_dano() - 3);
        }
        if(valor_dado == 2) {
            inimigo1.recebe_dano(get_dano() - 2);
            inimigo2.recebe_dano(get_dano() - 2);
            inimigo3.recebe_dano(get_dano() - 2);
        }
        else if(valor_dado == 3) {
            inimigo1.recebe_dano(get_dano());
            inimigo2.recebe_dano(get_dano());
            inimigo2.recebe_dano(get_dano());
        }
        else {
            inimigo1.recebe_dano(get_dano() + (valor_dado / 3));
            inimigo2.recebe_dano(get_dano() + (valor_dado / 3));
            inimigo3.recebe_dano(get_dano() + (valor_dado / 3));    
        }
    }
    if(get_tranformacao()==Urso){
        if(valor_dado == 1) inimigo1.recebe_dano(get_dano() - 1);
        if(valor_dado == 2) inimigo1.recebe_dano(get_dano());
        else if(valor_dado == 3) inimigo1.recebe_dano(get_dano()+1);
        else inimigo1.recebe_dano(get_dano() + (3*valor_dado / 4));
    }
    if(get_tranformacao()==Lobo){
        if(valor_dado == 1) {
            inimigo1.recebe_dano(get_dano() - 2);
            inimigo2.recebe_dano(get_dano() - 2);
        }
        if(valor_dado == 2) {
            inimigo1.recebe_dano(get_dano() - 1);
            inimigo2.recebe_dano(get_dano() - 1);
        }
        else if(valor_dado == 3) {
            inimigo1.recebe_dano(get_dano());
            inimigo2.recebe_dano(get_dano());
        }
        else {
            inimigo1.recebe_dano(get_dano() + (valor_dado / 2));
            inimigo2.recebe_dano(get_dano() + (valor_dado / 2));
        }
    }
}
