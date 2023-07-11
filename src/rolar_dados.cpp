#include "../include/rolar_dados.h"

using namespace std;

int Rolar_Dados::calcula_dado(int limite){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(1,limite);
    return d(rng);
}

Rolar_Dados::Rolar_Dados() {}

int Rolar_Dados::rolar_d06(){
    return calcula_dado(6);
}

int Rolar_Dados::rolar_d08(){
    return calcula_dado(8);
}

int Rolar_Dados::rolar_d10(){
    return calcula_dado(10);
}

int Rolar_Dados::rolar_d12(){
    return calcula_dado(12);
}

int Rolar_Dados::rolar_d20(){
    return calcula_dado(20);
}

