#ifndef CAO_INFERNAL_H
#define CAO_INFERNAL_H

#include "monstros.h"

class CaoInfernal: public Monstro{
    protected:
      static int _id;
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
    * @brief retorna a letra que representa o heroi
    */
    std::string get_letra() override;

    void ataque(int alvo, int valor_dado, std::vector<Personagem *> inimigos) override;
};

#endif
