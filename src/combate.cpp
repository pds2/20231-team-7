#include <iostream>

#include "../include/combate.h"
#include "../include/herois/time_heroi.h"

using namespace std;

Combate::Combate(
    Time_h &time
): _time(time) {}

void Combate::seta_posicoes(vector<Monstro *> monstros){
    Heroi *h1 = _time.get_h1();
    h1->set_posicao(0, 0);

    Heroi *h2 = _time.get_h2();
    h2->set_posicao(0, 1);

    for(unsigned i = 0; i < monstros.size(); i++){
        monstros.at(i)->set_posicao(4, i);
    }
}

bool Combate::entra_combate(vector<Monstro *> monstros){
    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();
    Monstro *m1 = monstros.at(0);
    Monstro *m2 = monstros.at(1);

    bool player_venceu = false;

    seta_posicoes(monstros);

    while((!h1->morto() || !h2->morto()) && (!m1->morto() || !m2->morto())){
        system("clear");
        _time.desenha_hud();

        h1->recebe_dano(5);
        h2->recebe_dano(3);

        system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.' var");
    }

    return player_venceu;
}
