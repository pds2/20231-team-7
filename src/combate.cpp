#include "../include/combate.h"
#include "../include/herois/time_heroi.h"

void Combate::entra_combate(Time_h &time, Monstro &m1, Monstro &m2){
    bool player_venceu = false;

    Heroi *h1 = time.get_h1();
    h1->set_posicao(0, 0);

    Heroi *h2 = time.get_h2();
    h2->set_posicao(0, 1);

    m1.set_posicao(4, 0);
    m2.set_posicao(4, 1);

    while((!h1->morto() && !h2->morto()) || (!m1.morto() && !m2.morto())){
        system("clear");
        
        time.desenha_hud();
        break;
    } 
}
