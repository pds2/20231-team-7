#ifndef MONSTROS_H
#define MONSTROS_H

#include "../personagem.h"
#include <vector>
#include <string>

 enum tamanho{
    _MIUDO, _PEQUENO, _MEDIO, _GRANDE, _ENORME, _IMENSO
 };

 class Monstro : public Personagem{
    private:
        int _exp;
    public:
         /*
         * @brief Cria um monstro.
         */  
        Monstro(std::string nome, int vida, int dano,int exp);
       
         /*
         * @brief Destroi um monstro.
         */          
        virtual ~Monstro();

         /*
         * @brief Retorna o tamanho do monstro.
         */
        virtual tamanho get_tamanho() = 0;

        /*
        * @brief Aumenta o nível do personagem.
        */
        void aumenta_nivel() override;

        /*
         * @brief Move o monstro uma casa a frente.
         */
        void move() override;

        /*
        * @brief Retorna falso.
        */
        bool eh_heroi() override;
 };



#endif 
