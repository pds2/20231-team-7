#ifndef TIME_HEROI_H
#define TIME_HEROI_H

#include "heroi.h"

class Time_h{
    private:
        std::pair<Heroi *,Heroi *> _time;
    public:
        /*
         * @brief Cria um time.
         */    
        Time_h();

        /*
         * @brief Acrescenta dois herois a time.
         */   
        Time_h(Heroi& h1, Heroi& h2);
        
        /*
         * @brief Deleta um time.
         */   
        ~Time_h();

        /*
         * @brief Retorna o heroi 1 do time.
         */   
        Heroi* get_h1();

        /*
         * @brief Define o heroi 1 do time.
         */   
        void set_h1(Heroi& h1);

        /*
         * @brief Retorna o heroi 2 do time.
         */   
        Heroi* get_h2();

        /*
         * @brief Define o heroi 2 do time.
         */
        void set_h2(Heroi& h2);

        /*
         * @brief Desenha o hud do time.
         */   
        void desenha_hud();
};

#endif
