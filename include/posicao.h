#ifndef POSICAO_H
#define POSICAO_H

class posicao_invalida_e {};

#include <utility>

class Posicao{
    private:
        int _x;
        int _y;
    public:
        /*
         * @brief Cria uma posiçao padrao (0,0).
         */
        Posicao();

        /*
         * @brief Cria uma posiçao especifica.
         */
        Posicao(int x, int y);

        /*
         * @brief Retorna a distancia ate outra posiçao.
         */
        double distancia(Posicao &adversario);

        /*
         * @brief Retorna o x da posiçao.
         */
        int get_x();

        /*
         * @brief Define novo x para a posiçao.
         */
        void set_x(int x);

        /*
         * @brief Retorna o y da posiçao.
         */
        int get_y();

        /*
         * @brief Define novo y para a posiçao.
         */
        void set_y(int y);
};

#endif
