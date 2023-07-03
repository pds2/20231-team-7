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
    
    if(_trans==Urso) _vida -= 5;
    if(_trans==Lobo) _vida -= 3;
    if(_trans==Falcao) _vida--;

    if(trans==Urso) _vida += 5;
    if(trans==Lobo) _vida += 3;
    if(trans==Falcao) _vida++;

    _trans= trans;
    if(_vida<=0) _vida=1;
}

void Druida::ataqueUrso(int valor_dado, std::vector<Personagem *> inimigos){
    if(inimigos.size()>1)
        throw alvos_demais_e();
    for(auto *p:inimigos){
        if(valor_dado == 1) 
            p->recebe_dano(get_dano() - 1);
        if(valor_dado == 2) 
            p->recebe_dano(get_dano());
        if(valor_dado == 3) 
            p->recebe_dano(get_dano()+1);
        if(valor_dado>3)
            p->recebe_dano(get_dano()  + (3*valor_dado / 4));
    }
}

void Druida::ataqueHumano(int valor_dado, std::vector<Personagem *> inimigos){
    if(inimigos.size()>1)
        throw alvos_demais_e();
    for(auto *p:inimigos){
        if(valor_dado == 1) 
            p->recebe_dano(get_dano() - 3);
        if(valor_dado == 2) 
            p->recebe_dano(get_dano() - 2);
        if(valor_dado == 3) 
            p->recebe_dano(get_dano());
        if(valor_dado>3)
            p->recebe_dano(get_dano()  + (valor_dado / 2));
    }
}

void Druida::ataqueFalcao(int valor_dado, std::vector<Personagem *> inimigos){
    if(inimigos.size()>3)
        throw alvos_demais_e();
    for(auto *p:inimigos){
        if(valor_dado == 1) 
            p->recebe_dano(get_dano() - 3);
        if(valor_dado == 2) 
            p->recebe_dano(get_dano() - 2);
        if(valor_dado == 3) 
            p->recebe_dano(get_dano()-1);
        if(valor_dado>3) 
            p->recebe_dano(get_dano()  + (valor_dado / 3));
    }
}

void Druida::ataqueLobo(int valor_dado, std::vector<Personagem *> inimigos){
    if(inimigos.size()>2)
        throw alvos_demais_e();
    for(auto *g:inimigos){
        if(valor_dado == 1) 
            g->recebe_dano(get_dano() - 2);
        if(valor_dado == 2) 
            g->recebe_dano(get_dano() - 1);
        if(valor_dado == 3) 
            g->recebe_dano(get_dano());
        if(valor_dado>3)
            g->recebe_dano(get_dano() + (valor_dado / 2));
    }
}

void Druida::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    for(Personagem *p: inimigos){
        if(get_nome() ==p->get_nome())
            throw personagem_ataca_a_si_mesmo_e();
    }
    if(valor_dado < 1)
        throw valor_dado_negativo_e();
    if(get_tranformacao()==Humano){
        ataqueHumano(valor_dado, inimigos);
    }
    if(get_tranformacao()==Falcao){
        ataqueFalcao(valor_dado, inimigos);
    }
    if(get_tranformacao()==Urso){
        ataqueUrso(valor_dado, inimigos);
    }
    if(get_tranformacao()==Lobo){
        ataqueLobo(valor_dado,inimigos);
    }
}
