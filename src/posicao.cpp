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

int Posicao::get_x(){
    return _x;
}

int Posicao::get_y(){
    return _y;
}
