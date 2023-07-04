#include <iostream>
using namespace std;

#include "../../../include/herois/mago/grimorio.h"

Grimorio::Grimorio() {
    adiciona_magia(1);
}

void Grimorio::adiciona_magia(int nivel){
    if(nivel == 1){
        _livro.push_back(_misseis);
        _livro.push_back(_onda);
    }
    if(nivel == 2){
        _livro.push_back(_marca);
    }
    if(nivel == 3){
        _livro.push_back(_flecha);
    }
}

void Grimorio::get_magias(){
    int i = 1;
    for(auto magia: _livro){
        cout << i << " - " << magia.get_nome() << std::endl;
        i++;
    }
}
