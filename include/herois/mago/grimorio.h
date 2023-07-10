#ifndef GRIMORIO_H
#define GRIMORIO_H

#include "magia.h"

#include<vector>

class Grimorio{
    private:
        Magia _misseis = Magia("misseis_magicos", 1, 4, 1, 2);
        Magia _onda = Magia("onda_trovejante", 1, 18, 4, 3); 
        Magia _marca = Magia("marca_da_punicao", 2, 12, 2, 3);
	    Magia _flecha = Magia("flecha_relampejante", 3, 32, 3, 4);

        
    public:
        /*
        * @brief constroi um grimorio
        */
        Grimorio();

        /*
        * @brief adiciona magias no vetor conforme o nível 
        */
        void adiciona_magia(int nivel);

        /*
         * @brief retorna as magias desblqueadas do grimorio.
        */
        std::vector<Magia> get_magias();

        /*
         * @brief retorna quantas magias desblqueadas do grimorio.
        */
        int get_num_magias();
};
#endif

