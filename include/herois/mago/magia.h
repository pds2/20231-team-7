#ifndef MAGIA_H
#define MAGIA_H

#include<string>

class Magia{
    private:
        std::string _nome;
        int _nivel;
        int _dano;
        double _distancia;
    public:
        /*
        * @brief Constroi uma magia
        */
        Magia(std::string nome, int nivel, int dano, double distancia);

        /*
        * @brief Retorna o nome
        */
        std::string get_nome();

        /*
        * @brief Retorna o nivel
        */
        int get_nivel();

        /*
        * @brief Retorna o dano
        */
        int get_dano();

        /*
        * @brief Retorna a distancia 
        */
        double get_distancia();
};

#endif
