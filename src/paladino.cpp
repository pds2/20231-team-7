#include <iostream>
#include <string>
using namespace std;

#include "../include/paladino.h"

   
Paladino::Paladino(
    string nome, 
    int vida,
    int vida_max,
    int dano
    ):Heroi(nome, vida, vida_max, dano),
    _mana(10), _manamax(10) {}


Classes Paladino::get_classe() const{
    return PALADINO;
}


unsigned int Paladino::get_mana(){
    return _mana;
}

   
void Paladino::recuperar_mana(){
    if(_mana<=(_manamax-2)) _mana=_mana+2;
    if(_mana==(_manamax-1)) _mana++;
}

    
void Paladino::magia_cura(Heroi &alvo, int valor_dado){


}
   
void Paladino::ataque(Personagem &inimigo, int valor_dado){
        
}
