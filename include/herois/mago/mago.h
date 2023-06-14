#ifndef MAGO_H
#define MAGO_H

#include "../heroi.h"
#include "grimorio.h"

class Mago : public Heroi {
    private:
        int _mana;
        Grimorio grimorio;
    public:
        /*
        * @brief cria um mago 
        */
        Mago(std::string nome, int vida, int dano);

        /*
        * @brief Retorna o dano de ataque do heroi.
         */
        void ataque(Personagem &inimigo, int valor_dado) override;

        /*
        * @brief Retorna a classe do personagem.
        */
        Classes get_classe() const override;

        /*
        * @brief retorna a mana
        */
        int get_mana();

        /*
        * @brief aumenta o nivel do mago.
        */
        void aumenta_nivel() override;

        /*
        @brief Retorna o grimorio do mago
        */
        void get_grimorio();
};

#endif
