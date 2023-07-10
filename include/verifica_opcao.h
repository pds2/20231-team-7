#ifndef VERIFICA_OPCAO_H
#define VERIFICA_OPCAO_H

#include <map>

#include "../third_party/termcolor.h"
#include "../include/herois/heroi.h"

class Verifica_opcao{
    protected:
        std::map<unsigned, std::string> _opcoes;

        /*
        * @brief Verifica se existem opçoes
        */ 
        bool existe_opcao(unsigned i);

        /*
        * @brief Retorna true se a opçao desejada existe 
        */ 
        virtual bool seleciona(unsigned);

        /*
        * @brief Mostra o menu ou a pergunta de uma opçao
        */ 
        virtual void mostra_menu();

        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_opcoes();
    public:
        /*
        * @brief Cria um verifica opçao
        */ 
        Verifica_opcao(unsigned num_opcoes);

        /*
        * @brief Destrutor de verifica opçao
        */ 
        virtual ~Verifica_opcao();

        /*
        * @brief Recebe do usuario a opçao desejada e retorna qual o seu numero
        */ 
        unsigned retorna_opcao();
};

class Escolhe_ataque: public Verifica_opcao{
    private:
        Heroi* _heroi;

        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe ataque armazena os ataques do heroi nas suas opçoes
        */ 
        Escolhe_ataque(Heroi* h);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_ataque();
};

class Escolhe_alvo: public Verifica_opcao{
    private:
        std::vector<Personagem *> _personagens;

        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe alvo e armazena os possiveis alvos para ataque no map;
        */ 
        Escolhe_alvo(std::vector<Personagem *>);

        /*
        * @brief Destrutor.
        */ 
        ~Escolhe_alvo();
};

class Escolhe_classe: public Verifica_opcao{
    private:
        /*
        * @brief Retorna true se a opçao desejada existe e apaga ela para a proxima chamada
        */ 
        bool seleciona(unsigned) override;

        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe classe e armazena as classes de heroi nas suas opçoes
        */ 
        Escolhe_classe(unsigned i);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_classe();

};

class Escolhe_menu: public Verifica_opcao{
    private:
        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe meno armazena as entradas de menu nas suas opçoes
        */ 
        Escolhe_menu(unsigned i);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_menu();
};

class Escolhe_saida: public Verifica_opcao{
    private:
        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe saida armazena sim e nao nas suas opçoes
        */ 
        Escolhe_saida(unsigned i);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_saida();
};

class Escolhe_salvar: public Verifica_opcao{
    private:
        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe salvar e armazena as opçoes de progressao nas suas opçoes
        */ 
        Escolhe_salvar(unsigned i);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_salvar();
    
};

class Escolhe_save: public Verifica_opcao{
    private:
        /*
        * @brief Mostra as opçoes armazenadas no map do tipo
        */ 
        void mostra_menu() override;
    public:
        /*
        * @brief Cria um escolhe save armazena os save slots nas suas opçoes
        */ 
        Escolhe_save(unsigned i);

        /*
        * @brief Destrutor
        */ 
        ~Escolhe_save();
};

#endif
