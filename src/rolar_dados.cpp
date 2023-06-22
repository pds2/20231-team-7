#include "../include/rolar_dados.h"

using namespace std;

Rolar_Dados::Rolar_Dados() {}

int Rolar_Dados::rolar_d04(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_04(1,4);
    return d_04(rng);
}

int Rolar_Dados::rolar_d06(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_06(1,6);
    return d_06(rng);
}

int Rolar_Dados::rolar_d08(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_08(1,8);
    return d_08(rng);
}

int Rolar_Dados::rolar_d10(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_10(1,10);
    return d_10(rng);
}

int Rolar_Dados::rolar_d12(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_12(1,12);
    return d_12(rng);
}

int Rolar_Dados::rolar_d20(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_20(1,20);
    return d_20(rng);
}

int Rolar_Dados::rolar_d100(){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d_100(1,100);
    return d_100(rng);
}
