#ifndef DAO_H
#define DAO_H

#include "monstros.h"
#include <string>

class Dao : public Monstro{
    private:
        static int _id;
    public:
    /*
    *@brief Cria um Dao
    */
    Dao();
    /*
    *@brief Destroi um Dao
    */
    ~Dao();
    /*
    @brief Retorna o tamanho do monstro
    */
   virtual tamanho get_tamanho() override;

    /*
    * @brief retorna a letra que representa o heroi
    */
    std::string get_letra() override;

    /*
   *@brief Funcao de ataque
   */
  void ataque(int alvo, int valor_dado, std::vector<Personagem *> inimigos) override;
};
#endif
