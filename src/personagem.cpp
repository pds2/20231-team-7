#include <iostream>
using namespace std;

#include "../include/personagem.h"

Personagem::Personagem(
    string nome,
    int vida,
    int dano
):  _nome(nome),
    _vida(vida),
    _dano(dano),
    _morto(false),
    _nivel(1),
    _lugar(Posicao()) {}

string Personagem::get_nome() const{
    return _nome;
}

int Personagem::get_vida(){
    return _vida;
}

void Personagem::set_vida(int vida){
    _vida = vida;
}

int Personagem::get_dano(){
    return _dano;
}

void Personagem::set_dano(int dano){
    _dano = dano;
}

Posicao Personagem::get_posicao(){
    return _lugar;
}

unsigned int Personagem::get_nivel(){
    return _nivel;
}

void Personagem::recebe_dano(int dano){
    if(dano <= 0) throw dano_negativo_e();

    _vida -= dano;
    if(_vida <= 0) _morto = true;
}

bool Personagem::morto(){
    return _morto;
}

void Personagem::ataque(Personagem &inimigo, int valor_dado){
    if(_nome == inimigo._nome)
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();

    if(valor_dado == 1) inimigo.recebe_dano(_dano - 3);
    if(valor_dado == 2) inimigo.recebe_dano(_dano - 2);
    else if(valor_dado == 3) inimigo.recebe_dano(_dano);
    else inimigo.recebe_dano(_dano + (valor_dado / 2));
}

void Personagem::aumenta_nivel(){
    _nivel++;
    _vida += 4;
    _dano += 4;
}
