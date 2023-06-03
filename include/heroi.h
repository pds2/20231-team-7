#ifndef HEROI_H
#define HEROI_H

#include <map>
#include <vector>

#include "personagem.h"

class impossivel_adicionar_exp_negativa_e {};
class habilidade_ja_existe_e {};
class habilidade_nao_existe_e {};

enum Classes {
    DRUIDA, GUERREIRO, MAGO, PALADINO
};

class Heroi: public Personagem {
    private:
        unsigned int _exp;
        std::map<std::string,bool> _habilidades;
    public:
         /*
         * @brief Cria um heroi.
         */       
        Heroi(std::string nome, int vida, int dano, std::string classe);

        /*
         * @brief Retorna a classe do personagem.
         */
        virtual Classes get_classe() const;

        /*
         * @brief Retorna a experiencia do heroi (exp).
         */
        unsigned int get_exp();

        /*
         * @brief Adiciona uma quantidade de experiencia para o heroi.
         *        Verifica se o heroi passou de nivel.
         */
        void ganha_exp(int exp);

        /*
         * @brief Aumenta o nivel do heroi e seus atributos base.
         */
        void aumenta_nivel() override; 

        /*
         * @brief Adiciona habilidade ao personagem, mas ainda bloqueada.
         */
        void adiciona_habilidade(std::string habilidade);

        /*
         * @brief Desbloqueia habilidade do heroi.
         */
        void desbloqueia_habilidade(std::string habilidade);

        /*
         * @brief Printa todas as habilidades já desbloqueadas pelo heroi.
         */
        void print_habilidades();
};

#endif

