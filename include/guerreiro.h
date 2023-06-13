#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "guerreiro.h"

class Guerreiro : public Heroi {
    private:
    
    public:
    /*
     * @brief Cria um guerreiro
     */
    Guerreiro();
    /*
     * @brief Retorna o dano de ataque do heroi.
     */
    void ataque(Personagem &inimigo, int valor_dado) override;
    /*
     * @brief Retorna a classe do personagem.
     */
    Classes get_classe() const override;
     
}
#endif