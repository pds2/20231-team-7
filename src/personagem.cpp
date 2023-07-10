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

int Personagem::get_dado(){
    return _dado_atual;
}

void Personagem::set_dado(int dado){
    _dado_atual = dado;
}

Posicao Personagem::get_posicao(){
    return _lugar;
}

void Personagem::set_posicao(int x, int y){
    _lugar.set_x(x);
    _lugar.set_y(y);
}

unsigned int Personagem::get_nivel(){
    return _nivel;
}

void Personagem::recebe_dano(int dano){
    if(dano < 0) throw dano_negativo_e();

    if(_vida <= dano){
        _vida = 0;
        _morto = true;
        return;
    }

    _vida -= dano;
}

bool Personagem::morto(){
    return _morto;
}

int Personagem::calcula_ataque(int dado){
    int diferenca = dado - 3;
    int aumento = 2;

    if(diferenca < 0){
        diferenca *= -1;
        aumento *= -1;
    }

    return (_dano + (aumento * diferenca));
}
