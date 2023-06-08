#include "../include/posicao.h"
#include <cmath>

Posicao::Posicao(){
    _x = 0;
    _y = 0;
}

Posicao::Posicao(int x, int y){
    _x = x;
    _y = y;
}
        
double Posicao::distancia(Posicao &adversario){
    return sqrt(pow(_x-adversario._x,2)+pow(_y-adversario._y,2));
}

Posicao Posicao::get_posicao(){
    Posicao parametro = Posicao(_x,_y);
    return parametro;
    }
