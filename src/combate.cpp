#include <iostream>
#include <iomanip>

#include "../include/combate.h"
#include "../include/herois/time_heroi.h"

using namespace std;

bool verifica_monstros(vector<Monstro *> monstros){
    unsigned mortos = 0;
    for(auto m: monstros)
        if(m->morto()) mortos++;

    return(mortos == monstros.size());
}

void Combate::desenha_hud(){
    system("clear");
    _time.desenha_hud();
    hud_monstro(); 
}

Combate::Combate(
    Time_h &time
): _time(time) {}

Combate::~Combate(){
    for(auto m: _monstros)
        delete m;
}

void Combate::seta_posicoes(){
    Heroi *h1 = _time.get_h1();
    h1->set_posicao(0, 0);

    Heroi *h2 = _time.get_h2();
    h2->set_posicao(0, 1);

    for(unsigned i = 0; i < _monstros.size(); i++)
        _monstros.at(i)->set_posicao(4, i);
}

void Combate::hud_monstro(){
    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| " << termcolor::red << left << setw(12) << setfill(' ') << _monstros.at(i)->get_nome()
             << string(12, ' ') << right << termcolor::reset;
    }
    cout << "|" << endl;

    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| Vida: " << left << setw(2) << setfill(' ');
        (_monstros.at(i)->get_vida() == 0) ? cout << termcolor::red << setw(2) << setfill(' ')
        << _monstros.at(i)->get_vida() << termcolor::reset
        : cout << _monstros.at(i)->get_vida();
        cout << string(16, ' ') << right;
    }
    cout << "|" << endl;

    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| Dano: " << setw(2) << setfill(' ') << _monstros.at(i)->get_dano() << string(16, ' ')
             << right;
    }
    cout << "|" << endl;

    for(unsigned i = 0; i < _monstros.size(); i++){
        Posicao posicao;
        posicao = _monstros.at(i)->get_posicao();
        cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(12, ' ');
    }
    cout << "|" << endl;

    cout << string(79, '-') << endl; 
}

bool Combate::entra_combate(vector<Monstro *> monstros){
    _monstros = monstros;

    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();
    Monstro *m1 = monstros.at(0);
    Monstro *m2 = monstros.at(1);
    Monstro *m3 = monstros.at(2);

    seta_posicoes();

    bool player_venceu = false;
    while((h1->morto() == false || h2->morto() == false) &&
          (m1->morto() == false || m2->morto() == false || m3->morto() == false))
    {
        desenha_hud();

        h1->recebe_dano(4);
        h2->recebe_dano(3);
        m1->recebe_dano(10);
        m2->recebe_dano(10);
        m3->recebe_dano(10);

        player_venceu = verifica_monstros(_monstros);
        system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");
    }

    desenha_hud();
    system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

    return player_venceu;
}
