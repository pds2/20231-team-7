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

        ~Mago();

        /*
        * @brief Retorna o dano de ataque do heroi.
         */
        void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;

        /*
        * @brief Aplica o dano de ataque de uma magia.
         */
        void lança_magia(int nummagia,int valor_dado, std::vector<Personagem *> inimigos);

        /*
        * @brief Retorna a classe do personagem.
        */
        Classes get_classe() const override;

        /*
        * @brief retorna o numero de habilidades que o personagem tem
        */
        unsigned get_num_habilidades() override;

        /*
        * @brief retorna a letra que representa o heroi
        */
        std::string get_letra() override;

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
        std::vector<std::string> get_habilidades() override;
};

#endif
