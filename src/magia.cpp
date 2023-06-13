#include "../include/magia.h"

Magia::Magia(
    std::string nome,
    int nivel,
    int dano,
    float distancia
):  _nome(nome),
    _nivel(nivel),
    _dano(dano),
    _distancia(distancia) {}

std::string Magia::get_nome(){
    return _nome;
}

int Magia::get_nivel(){
    return _nivel;
}

int Magia::get_dano(){
    return _dano;
}

float Magia::get_distancia(){
    return _distancia;
}