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
   *@brief Retorna a habilidade do monstro
   */
   virtual habilidade get_habilidade() override;
   /*
   *@brief Funcao de ataque
   */
  void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;
};
#endif
