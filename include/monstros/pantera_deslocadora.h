#ifndef PANTERA_DESLOCADORA_H
#define PANTERA_DESLOCADORA_H

#include "monstros.h"

class PanteraDeslocadora: public Monstro{
    private:

    public:
    /*
     * @brief Cria uma pantera deslocadora.
    */
    PanteraDeslocadora();

    /*
     * @brief Destroi a pantera deslocadora.
    */
    ~PanteraDeslocadora() override;

    /*
     * @brief Obter o tamanho da pantera deslocadora.
    */
    tamanho get_tamanho() override;

    /*
     * @brief Obter a habilidade da pantera deslocadora.
    */
    habilidade get_habilidade() override;

    void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;
};


#endif
