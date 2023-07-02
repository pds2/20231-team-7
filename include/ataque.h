#ifndef ATAQUE_H
#define ATAQUE_H

#include "herois/heroi.h"
#include "monstros/monstros.h"

#include "herois/time_heroi.h"

class Ataque {
    private:

    public:
        virtual void ataque(unsigned atq) = 0;
};

#endif


