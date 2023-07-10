#ifndef VERIFICA_OPCAO_H
#define VERIFICA_OPCAO_H

#include <map>

#include "../third_party/termcolor.h"
#include "../include/herois/heroi.h"

class Verifica_opcao{
    protected:
        std::map<unsigned, std::string> _opcoes;
        bool existe_opcao(unsigned i);
        virtual bool seleciona(unsigned);
        virtual void mostra_menu();
        void mostra_opcoes();
    public:
        Verifica_opcao(unsigned num_opcoes);
        virtual ~Verifica_opcao();

        unsigned retorna_opcao();
};

class Escolhe_ataque: public Verifica_opcao{
    private:
        Heroi* _heroi;
        void mostra_menu() override;
    public:
        Escolhe_ataque(Heroi* h);
        ~Escolhe_ataque();
};

class Escolhe_classe: public Verifica_opcao{
    private:
        bool seleciona(unsigned) override;
        void mostra_menu() override;
    public:
        Escolhe_classe(unsigned i);
        ~Escolhe_classe();

};

class Escolhe_menu: public Verifica_opcao{
    private:
        void mostra_menu() override;
    public:
        Escolhe_menu(unsigned i);
        ~Escolhe_menu();
};

class Escolhe_saida: public Verifica_opcao{
    private:
        void mostra_menu() override;
    public:
        Escolhe_saida(unsigned i);
        ~Escolhe_saida();
};

class Escolhe_salvar: public Verifica_opcao{
    private:
        void mostra_menu() override;
    public:
        Escolhe_salvar(unsigned i);
        ~Escolhe_salvar();
    
};

class Escolhe_save: public Verifica_opcao{
    public:
        Escolhe_save(unsigned i);
        ~Escolhe_save();
};

#endif