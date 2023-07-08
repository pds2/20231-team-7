#ifndef VERIFICA_OPCAO_H
#define VERIFICA_OPCAO_H

#include <map>

#include "../third_party/termcolor.h"
#include "../include/herois/heroi.h"

class Verifica_opcao{
    protected:
        std::map<int, std::string> _opcoes; 
    public:
        Verifica_opcao(int num_opcoes);
        virtual ~Verifica_opcao();
        bool existe_opcao(int i);
        void mostra_opcoes();
        void mostra_ataques(Heroi& h);
        int retorna_opcao();
};

class Escolhe_classe: public Verifica_opcao{
    public:
        Escolhe_classe(int i);
        ~Escolhe_classe();
};

class Escolhe_menu: public Verifica_opcao{
    public:
        Escolhe_menu(int i);
        ~Escolhe_menu();
};

class Escolhe_saida: public Verifica_opcao{
    public:
        Escolhe_saida(int i);
        ~Escolhe_saida();
};

class Escolhe_save: public Verifica_opcao{
    public:
        Escolhe_save(int i);
        ~Escolhe_save();
};

#endif
