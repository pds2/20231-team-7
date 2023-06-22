#ifndef POSICAO_H
#define POSICAO_H

class Posicao{
    private:
        int _x;
        int _y;
    public:
        Posicao();
        Posicao(int x, int y);
        double distancia(Posicao &adversario);
        int get_x();
        void set_x(int x);
        int get_y();
        void set_y(int y);
};

#endif
