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
        Posicao get_posicao();

};

#endif