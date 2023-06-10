#include "../include/rolar_dados.h"

using namespace std;

Rolar_Dados::Rolar_Dados() {}

int Rolar_Dados::rolar_d04(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 4);
    return random;
}

int Rolar_Dados::rolar_d06(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 6);
    return random;
}

int Rolar_Dados::rolar_d08(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 8);
    return random;
}

int Rolar_Dados::rolar_d10(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 10);
    return random;
}

int Rolar_Dados::rolar_d12(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 12);
    return random;
}

int Rolar_Dados::rolar_d20(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 20);
    return random;
}

int Rolar_Dados::rolar_d100(){
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 100);
    return random;
}
