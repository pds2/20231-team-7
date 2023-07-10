#ifndef PALADINO_H
#define PALADINO_H

#include "heroi.h"
#include "../personagem.h"


class Paladino: public Heroi{
    private:
        unsigned int _mana; 
        unsigned int _manamax;
        std::vector<std::string> _ataques;
    public:
         /*
         * @brief Cria um paladino.
         */       
        Paladino(std::string nome, int vida, int dano);

        ~Paladino();

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
         * @brief Aumenta o nivel do paladino e seus atributos base.
         */
        void aumenta_nivel() override; 

        /*
         * @brief Retorna a mana atual do paladino.
         */
        unsigned int get_mana();

        /*
         * @brief Recupera mana num valor fixo.
         */
        void recuperar_mana();

        /*
         * @brief Ação de cura do paladino.
         */
        void magia_cura(Heroi &alvo,int valor_dado);

        /*
         * @brief Ação de ataque do paladino.
         */
        void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;

       /*
        * @brief Retorna as habilidades do paladino.
        */
        std::vector<std::string> get_habilidades() override;
};

#endif
