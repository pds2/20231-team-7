#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>

class invalid_option_e{};

class Sistema{
    private:
        std::string _opcao;
    public:
        Sistema();
        void mostra_menu();
        void mostra_creditos();
        void inicia_menu();
        void inicia_jogo();
};

#endif
