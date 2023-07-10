#ifndef ROLAR_DADOS_H
#define ROLAR_DADOS_H

#include <iostream>
#include <cstdlib>
#include <random>

class Rolar_Dados{
    public:
    /*
    * @brief Constroi a classe de dados.
    */  
    Rolar_Dados();

    /*
    * @brief Retorna um valor aleatorio entre 1 e 6.
    */  
    int rolar_d06();

    /*
    * @brief Retorna um valor aleatorio entre 1 e 8.
    */  
    int rolar_d08();

    /*
    * @brief Retorna um valor aleatorio entre 1 e 10.
    */  
    int rolar_d10();

    /*
    * @brief Retorna um valor aleatorio entre 1 e 12.
    */  
    int rolar_d12();

    /*
    * @brief Retorna um valor aleatorio entre 1 e 20.
    */  
    int rolar_d20();
};

#endif
