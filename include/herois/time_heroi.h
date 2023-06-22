#ifndef TIME_HEROI_H
#define TIME_HEROI_H

#include "heroi.h"

class Time_h{
    private:
        std::pair<Heroi *,Heroi *> _time;
    public:
        Time_h(Heroi& h1, Heroi& h2);

};

#endif
