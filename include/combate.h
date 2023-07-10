#ifndef COMBATE_H
#define COMBATE_H

#include "herois/heroi.h"
#include "monstros/monstros.h"

#include "herois/time_heroi.h"

class Combate{
    private:
        Time_h _time;
        std::vector<Monstro *> _monstros;

        std::vector<Personagem *> _ordem_combate;
    public:
        Combate(Time_h &time);
        ~Combate();
        bool entra_combate(std::vector<Monstro *> monstros);
        void rola_dados(int);
        void organiza_ordem();
        std::pair<unsigned,unsigned> ataque_heroi(int n);
        void seta_posicoes();
        void hud_monstro();
        void desenha_hud();
        void desenha_tabuleiro();
};

#endif
