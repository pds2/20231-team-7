#include <iostream>

#include "../include/combate.h"
#include "../include/herois/time_heroi.h"

using namespace std;

bool Combate::entra_combate(Time_h &time, Monstro &m1, Monstro &m2){
    bool player_venceu = false;

    Heroi *h1 = time.get_h1();
    h1->set_posicao(0, 0);

    Heroi *h2 = time.get_h2();
    h2->set_posicao(0, 1);

    m1.set_posicao(4, 0);
    m2.set_posicao(4, 1);

    while((!h1->morto() || !h2->morto()) && (!m1.morto() || !m2.morto())){
        system("clear");
        time.desenha_hud();

        h1->recebe_dano(5);
        h2->recebe_dano(3);

        system("read -p 'Aperte ENTER para ir para o proximo turno.' var");
    }

    return player_venceu;
}
