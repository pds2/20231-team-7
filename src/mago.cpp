#include <iostream>
using namespace std;

#include "../include/mago.h"
#include "../include/grimorio.h"
#include <set>

Mago::Mago(
    string nome,
    int vida,
    int vida_max,
    int dano
) : Heroi (nome, vida, vida_max, dano),
   _mana(5) {}

void Mago::ataque(Personagem &inimigo, int valor_dado){
    if(get_nome()==inimigo.get_nome()){
        throw personagem_ataca_a_si_mesmo_e();
    }
    else if(valor_dado <= 0){
        throw valor_dado_negativo_e();
    }
    else{
        inimigo.recebe_dano(get_dano());
    }
}

Classes Mago::get_classe() const{
    return Classes::MAGO;
}

int Mago::get_mana(){
    return _mana;
}

void Mago::aumenta_nivel(){
    _nivel ++;
}

void Mago::get_grimorio(){
   for(auto it = livro.begin(); it != livro.end(); it++){
       cout << *it << " ";
   }
}

