#ifndef GRIMORIO_H
#define GRIMORIO_H

#include "magia.h"

#include<set>

class Grimorio{
    private:
        std::set<Magia> livro;
        Magia _misseis = Magia("misseis_magicos", 1, 4, 1);
        Magia _onda = Magia("onda_trovejante", 1, 18, 4.5); 
        Magia _marca = Magia("marca_da_punicao", 2, 12, 2.5);
        Magia _flecha = Magia("flecha_relampejante", 3, 32, 3.0);
    public:
        /*
        * @brief constroi um grimorio
        */
        Grimorio();

        /*
        * @brief adiciona magias no vetor conforme o nível 
        */
        void adiciona_magia(int nivel);
};

#endif