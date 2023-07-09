#include <iostream>
using namespace std;

#include "../../../include/herois/mago/mago.h"
#include "../../../include/herois/mago/grimorio.h"

Mago::Mago(
    string nome,
    int vida,
    int dano
) : Heroi (nome, vida, dano),
   _mana(10) {}

Mago::~Mago() {}

void Mago::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    for(auto inimigo: inimigos) 
        if(get_nome()==inimigo->get_nome()) throw personagem_ataca_a_si_mesmo_e();

    if(valor_dado <= 0){
        throw valor_dado_negativo_e();
    } else{
        for(auto inimigo: inimigos)
            inimigo->recebe_dano(get_dano());
    }
}

Classes Mago::get_classe() const{
    return Classes::MAGO;
}

char const* Mago::get_letra(){
    return "M";
}

int Mago::get_mana(){
    return _mana;
}

void Mago::aumenta_nivel(){
    _nivel ++;
    _vida += 3;
    _vida_max += 3;
    _dano += 3;
    _mana += 3;

    grimorio.adiciona_magia(_nivel);

    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
}

void Mago::print_habilidades(){
    grimorio.get_magias();
}
