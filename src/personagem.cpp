#include "../include/personagem.h"

using namespace std;

Personagem::Personagem(
    string nome
):  _nome(nome),
    _morto(false),
    _nivel(1) {
}

string Personagem::get_nome() const{
    return _nome;
}

int Personagem::get_vida(){
    return _vida;
}

int Personagem::get_dano(){
    return _dano;
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

void Personagem::aumenta_nivel(){
    _nivel++;
}
