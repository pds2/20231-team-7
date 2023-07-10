#ifndef MAGIA_H
#define MAGIA_H

#include<string>

class magia_fora_do_range_e{};

class Magia{
    private:
        std::string _nome;
        int _nivel;
        int _dano;
        double _distancia;
        int _custo;
    public:
        /*
        * @brief Constroi uma magia
        */
        Magia(std::string nome, int nivel, int dano, double distancia,int custo);

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
        * @brief Retorna o custo de mana da magia
        */
        int get_custo();

        /*
        * @brief Retorna a distancia 
        */
        double get_distancia();
};

#endif
