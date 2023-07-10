#include "../../../include/herois/mago/magia.h"

Magia::Magia(
    std::string nome,
    int nivel,
    int dano,
    double distancia,
    int custo
):  _nome(nome),
    _nivel(nivel),
    _dano(dano),
    _distancia(distancia),
    _custo(custo) {}

std::string Magia::get_nome(){
    return _nome;
}

int Magia::get_nivel(){
    return _nivel;
}

int Magia::get_dano(){
    return _dano;
}

int Magia::get_custo(){
    return _custo;
}

double Magia::get_distancia(){
    return _distancia;
}
