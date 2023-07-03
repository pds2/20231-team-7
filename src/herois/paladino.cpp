#include <iostream>
#include <string>
using namespace std;

#include "../../include/herois/paladino.h"

Paladino::Paladino(
    string nome, 
    int vida,
    int dano
    ): Heroi(nome, vida, dano),
    _mana(10), _manamax(10) {}


Classes Paladino::get_classe() const{
    return Classes::PALADINO;
}


unsigned int Paladino::get_mana(){
    return _mana;
}

void Paladino::aumenta_nivel(){
    _nivel++;
    _vida += 3;
    _vida_max +=3;
    _dano += 3;
    _mana += 4;
    _manamax += 4;


    string msg = "Nivel subiu para ";
    msg += std::to_string(_nivel);
    msg += "!!";

    // colore a mensagem
	cout << "\033[" << 31 << ";" << 3 << ";" << 92 << "m" << msg << "\033[0m";
    cout << endl;
}

   
void Paladino::recuperar_mana(){
    if(_mana <= (_manamax-2)) _mana=_mana+2;
    if(_mana == (_manamax-1)) _mana++;
}

    
void Paladino::magia_cura(Heroi &alvo, int valor_dado){
    if(_mana<2) throw mana_insuficiente_e();
    if(valor_dado < 1) throw valor_dado_negativo_e();

    alvo.recebe_cura(valor_dado);
    _mana-=2;
}
   
void Paladino::ataque(int valor_dado, std::vector<Personagem *> inimigos){
    if(get_nome() == inimigos[0]->get_nome())
        throw personagem_ataca_a_si_mesmo_e();
    if(valor_dado < 1)
        throw valor_dado_negativo_e();
    if(inimigos.size()>1)
        throw alvos_demais_e();

    for(auto *g :inimigos){
        if(valor_dado == 1) g->recebe_dano(_dano - 2);
        if(valor_dado == 2) g->recebe_dano(_dano - 1);
        else if(valor_dado == 3) g->recebe_dano(_dano);
        else g->recebe_dano(_dano + ((valor_dado / 2)+1));
    }
}
