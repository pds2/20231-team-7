#ifndef CAO_INFERNAL_H
#define CAO_INFERNAL_H

#include "monstros.h"

class CaoInfernal: public Monstro{
    public:
    /*
     * @brief Cria o cão infernal.
    */
    CaoInfernal();

    /*
    * @brief Destroi o cão infernal.
    */
    ~CaoInfernal();

    /*
     * @brief Obter o tamanho do cão infernal.
     */
    tamanho get_tamanho() override;

    /*
    * @brief Obter a habilidade do cão infernal.
    */
    habilidade get_habilidade() override;

    void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;
};

#endif
