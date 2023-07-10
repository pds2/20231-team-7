#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
#include <vector>
#include <iostream>

#include "posicao.h"
#include "../third_party/termcolor.h"

class dano_negativo_e {};
class valor_dado_negativo_e {};
class personagem_ataca_a_si_mesmo_e {};

class Personagem{
    private:
        const std::string _nome;
    protected:
        int _vida;
        int _dano;
        bool _morto;
        unsigned int _nivel;
        int _dado_atual;
        Posicao _lugar;
    public:
        /*
         * @brief Cria um personagem.
         */
        Personagem(std::string nome, int vida, int dano);

        /*
         * @brief Retorna o nome do personagem.
         */
        std::string get_nome() const;

        /*
         * @brief Retorna a primeira letra da classe do heroi.
         */        
        virtual std::string get_letra() = 0;

        /*
         * @brief Retorna a vida do personagem.
         */
        int get_vida();

        /*
         * @brief Altera vida do personagem.
         */
        void set_vida(int vida);

        /*
         * @brief Retorna o dano do personagem.
         */
        int get_dano();

        /*
         * @brief Altera dano do personagem.
         */
        void set_dano(int dano);

        /*
         * @brief Retorna o dado atual do personagem.
         */        
        int get_dado();

        /*
         * @brief Seta um valor dado novo para o personagem.
         */
        void set_dado(int dado);

        /*
         * @brief Retorna o nivel do personagem.
         */
        unsigned int get_nivel();

        /*
         * @brief Retorna a posicao do personagem.
         */
        Posicao get_posicao();

        /*
         * @brief Define a posicao do personagem.
         */
        void set_posicao(int x, int y);

        /*
         * @brief Diminui a vida do personagem de acordo com o dano.
         */
        void recebe_dano(int dano);

        /*
         * @brief Retorna o estado do personagem (morto / vivo).
         */
        bool morto();

        /*
         * @brief Calcula o dano do ataque baseado no valor de um dado entre 1 e 6.
         */
        int calcula_ataque(int dado);

        /*
         * @brief Retorna o dano de ataque do personagem.
         */
        virtual void ataque(int alvo, int valor_dado, std::vector<Personagem *> inimigos) = 0;

        /*
         * @brief Aumenta o nível do personagem.
         */
        virtual void aumenta_nivel() = 0;

        /*
         * @brief Retorna se o personagem é heroi ou nao.
         */
        virtual bool eh_heroi() = 0;
};

#endif
