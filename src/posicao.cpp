#include "../include/posicao.h"
#include <cmath>

Posicao::Posicao(){
    _x = 0;
    _y = 0;
}

Posicao::Posicao(int x, int y){
    if((x < 0 || x > 4) || (y < 0 || y > 3)) throw posicao_invalida_e();
    _x = x;
    _y = y;
}
        
double Posicao::distancia(Posicao &adversario){
    return sqrt(pow(_x-adversario._x,2)+pow(_y-adversario._y,2));
}

int Posicao::get_x(){
    return _x;
}

void Posicao::set_x(int x){
    _x = x;
}

int Posicao::get_y(){
    return _y;
}

void Posicao::set_y(int y){
    _y = y;
}
