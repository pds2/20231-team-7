#ifndef GRIMORIO_H
#define GRIMORIO_H

#include "magia.h"

#include<vector>

class Grimorio{
    private:
        std::vector<Magia> _livro;
        Magia _misseis = Magia("Misseis_magicos", 1, 4, 1);
        Magia _onda = Magia("Onda_trovejante", 1, 18, 4); 
        Magia _marca = Magia("Marca_da_punicao", 2, 12, 2);
        Magia _flecha = Magia("Flecha_relampejante", 3, 32, 3);
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
        std::vector<std::string> get_magias();

        /*
         * @brief retorna quantas magias desblqueadas do grimorio.
        */
        int get_num_magias();
};

#endif
