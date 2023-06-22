#ifndef TIME_HEROI_H
#define TIME_HEROI_H

#include "heroi.h"

class Time_h{
    private:
        std::pair<Heroi *,Heroi *> _time;
    public:
        Time_h();

        Time_h(Heroi& h1, Heroi& h2);
        
        ~Time_h();

        Heroi* get_h1();

        void set_h1(Heroi& h1);

        Heroi* get_h2();

        void set_h2(Heroi& h2);

        void desenha_hud();
};

#endif
