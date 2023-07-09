#ifndef SISTEMA_H
#define SISTEMA_H

#include "../include/herois/time_heroi.h"
#include "monstros/monstros.h"

#include <string>
#include <vector>

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
        void roda_jogo();
        void inicia_jogo();
        void encerra_jogo();
        void salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual);
        void carrega_save(unsigned int numslot);
        void carrega_jogo();
        std::vector<Monstro *> gera_fase(int numfase);
};

#endif
