#ifndef GUERREIRO_H
#define GUERREIRO_H

#include "heroi.h"

class Guerreiro : public Heroi {
    private:
        std::set<std::string> _ataques;
    public:
    /*
     * @brief Cria um guerreiro
     */
    Guerreiro(std::string nome, int vida, int dano);
    
    /*
     * @brief Retorna o dano de ataque do heroi.
     */
    void ataque(int valor_dadom, std::vector<Personagem *> inimigos) override;

    /*
     * @brief Retorna a classe do personagem.
     */
    Classes get_classe() const override;

    char const* get_letra() override;
     
    void aumenta_nivel() override;

    /*
     * @brief Retorna as habilidades do guerreiro.
     */
    void print_habilidades() override;
};

#endif
