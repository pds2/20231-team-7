#ifndef COMBATE_H
#define COMBATE_H

#include "herois/heroi.h"
#include "monstros/monstros.h"
#include "ataque.h"

#include "herois/time_heroi.h"

class Combate: public Ataque {
    private:
        Time_h _time;
    public:
        Combate(Time_h &time);
        bool entra_combate(std::vector<Monstro *> monstros);
        void seta_posicoes(std::vector<Monstro *> monstros);
};

#endif

