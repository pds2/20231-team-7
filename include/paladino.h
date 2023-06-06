#ifndef PALADINO_H
#define PALADINO_H

#include "heroi.h"
#include "personagem.h"


class Paladino: public Heroi{
    private:
        unsigned int _mana; 
        unsigned int _manamax;
    public:
         /*
         * @brief Cria um paladino.
         */       
        Paladino(std::string nome, int vida, int vida_max, int dano);

        /*
         * @brief Retorna a classe do personagem.
         */
        Classes get_classe() const override;

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
        void ataque(Personagem &inimigo, int valor_dado) override;

};

#endif
