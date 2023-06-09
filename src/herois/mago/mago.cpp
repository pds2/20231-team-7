#include <iostream>
using namespace std;

#include "../../../include/herois/mago/mago.h"
#include "../../../include/herois/mago/grimorio.h"

Mago::Mago(
    string nome,
    int vida,
    int dano
) : Heroi (nome, vida, dano),
   _mana(12),
   _manamax(12) {}

Mago::~Mago() {}


void Mago::lança_magia(int nummagia,int valor_dado, std::vector<Personagem *> inimigos){
    if(nummagia<grimorio.get_num_magias()){
        nummagia-=1;
        for(auto inimigo: inimigos) 
            if(get_nome()==inimigo->get_nome()) throw personagem_ataca_a_si_mesmo_e();

        if(valor_dado <= 0){
            throw valor_dado_negativo_e();
        } else{
            for(auto inimigo: inimigos){
                if(_mana>grimorio.get_magias().at(nummagia).get_custo()){
                    if(grimorio.get_magias().at(nummagia).get_distancia()>get_posicao().distancia(inimigo->get_posicao()))
                        inimigo->recebe_dano(grimorio.get_magias().at(nummagia).get_dano()+valor_dado*2);
                    else throw magia_fora_do_range_e();
                    _mana-=grimorio.get_magias().at(nummagia).get_custo();
                }
                else throw mana_insuficiente_e();
            }
        }
    }
    else if(nummagia==(grimorio.get_num_magias())) recuperar_mana();
}

void Mago::ataque(int num_ataque, int valor_dado, std::vector<Personagem *> inimigos){
    if(num_ataque==(get_num_habilidades()+1)) recuperar_mana();
    else lança_magia(num_ataque, valor_dado, inimigos); 
}

void Mago::recuperar_mana(){
    if(_mana <= (_manamax-5)) _mana=_mana+5;
    if(_mana > (_manamax-5)) _mana=_manamax;
}

Classes Mago::get_classe() const{
    return Classes::MAGO;
}

unsigned Mago::get_num_habilidades(){
    return grimorio.get_num_magias()+1; 
}

string Mago::get_letra(){
    return "M";
}

unsigned int Mago::get_mana(){
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

vector<string> Mago::get_habilidades(){
    vector<string> magias;
    for(auto m:grimorio.get_magias())
        magias.push_back(m.get_nome());
    magias.push_back("Recuperar mana");
    return magias;
}
