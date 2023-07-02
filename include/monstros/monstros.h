#ifndef MONSTROS_H
#define MONSTROS_H

#include "../personagem.h"
#include <vector>
#include <string>

 enum tamanho{
    _MIUDO, _PEQUENO, _MEDIO, _GRANDE, _ENORME, _IMENSO
 };

 enum habilidade{
    _FORCA, _DESTREZA, _INTELIGENCIA, _SABEDORIA
 };


 class Monstro : public Personagem{
    private:
        int _nivel_de_desafio;
        int _classe_de_armadura;
        int _valor_nivel_minimo;
        std::vector<std::string> imune;
    public:
        /*
         * @brief Cria um monstro.
         */  
        Monstro(std::string nome, int vida, int dano,int nivel_de_desafio,
                 int classe_de_armadura, int valor_nivel_minimo);
       
        /*
         * @brief Destroi um monstro.
         */          
        virtual ~Monstro();

        /*
         * @brief Retorna o tamanho do monstro.
         */
        tamanho get_tamanho();

        /*
         * @brief Retorna a habilidade do monstro.
         */
        habilidade get_habilidade();

        void aumenta_nivel() override;

        void ataque(int valor_dado, std::vector<Personagem *> inimigos) override;
 };



#endif 
