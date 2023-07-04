#ifndef SISTEMA_H
#define SISTEMA_H

#include "../include/herois/time_heroi.h"

#include <string>

class invalid_option_e{};
class slot_invalido_e{};

class Sistema{
    private:
        std::string _opcao;
        Time_h _herois;
    public:
        Sistema();
        void inicia_menu();
        void cria_personagens();
        void inicia_jogo();
        void encerra_jogo();
        void salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual);
        void carrega_jogo(unsigned int numslot);
};

#endif
