#ifndef COMBATE_H
#define COMBATE_H

#include "herois/heroi.h"
#include "monstros/monstros.h"

#include "herois/time_heroi.h"

class Combate{
    public:
        void entra_combate(Time_h &time, Monstro &m1, Monstro &m2);
};

#endif

