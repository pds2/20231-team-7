#ifndef COMBATE_H
#define COMBATE_H

#include "herois/heroi.h"
#include "monstros/monstros.h"

#include "herois/time_heroi.h"

class Combate{
    private:
        Time_h _time;
        std::vector<Monstro *> _monstros;
    public:
        Combate(Time_h &time);
        ~Combate();
        bool entra_combate(std::vector<Monstro *> monstros);
        void seta_posicoes();
        void hud_monstro();
        void desenha_hud();
};

#endif

