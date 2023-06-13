#include <iostream>
using namespace std;

#include "../include/grimorio.h"

Grimorio::Grimorio() {
    adiciona_magia(); 
}

void Grimorio::adiciona_magia(int nivel){
    if(get_nivel() == 1){
        livro.insert(_misseis);
        livro.insert(_onda);
    }
    if(get_nivel() == 2){
        livro.insert(_marca);
    }
    if(get_nivel() == 3){
        livro.insert(_flecha);
    }
}