#ifndef SISTEMA_H
#define SISTEMA_H

#include "../include/herois/mago/mago.h"
#include "../include/herois/guerreiro.h"
#include "../include/herois/druida.h"
#include "../include/herois/paladino.h"
#include "../include/rolar_dados.h"

#include <string>

class invalid_option_e{};
class slot_invalido_e{};

class Sistema{
    private:
        std::string _opcao;
    public:
        Sistema();
        void mostra_menu();
        void mostra_creditos();
        void inicia_menu();
        void inicia_jogo();
        void salva_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual);
        void carrega_jogo(unsigned int numslot,Heroi &heroi1, Heroi &heroi2,int faseatual);
};

#endif
