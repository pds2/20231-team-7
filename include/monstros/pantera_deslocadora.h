#ifndef PANTERA_DESLOCADORA_H
#define PANTERA_DESLOCADORA_H

#include "monstros.h"

class PanteraDeslocadora: public Monstro{
    private:
        static int _id;
    public:
    /*
     * @brief Cria uma pantera deslocadora.
    */
    PanteraDeslocadora();

    /*
     * @brief Destroi a pantera deslocadora.
    */
    ~PanteraDeslocadora();

    /*
     * @brief Obter o tamanho da pantera deslocadora.
    */
    tamanho get_tamanho() override;

    /*
    * @brief retorna a letra que representa o heroi
    */
    std::string get_letra() override;

    /*
    * @brief Funcao de ataque
    */
    void ataque(int num_ataque, int valor_dado, std::vector<Personagem *> inimigos) override;
};


#endif
