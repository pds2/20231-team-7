#ifndef GOLEM_DE_CARNE_H
#define GOLEM_DE_CARNE_H

#include "monstros.h"
#include <string>

class Golem_de_carne : public Monstro{
    private:
        static int _id;
    public:
    /*
    * @brief Cria um Golem de Carne
    */
   Golem_de_carne();
    /*
    * @brief Destroi um Golem de Carne
    */
   ~Golem_de_carne();
    /*
    * @brief Retorna o tamanho do monstro.
    */
    virtual tamanho get_tamanho() override;
    /*
    * @brief Retorna a habilidade do monstro.
    */
    virtual habilidade get_habilidade() override;
    /*
    * @brief Funcao de ataque
    */
   void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;
};

#endif
