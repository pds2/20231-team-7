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

vector<string> Grimorio::get_magias(){
    vector<string> magias;
    for(auto magia: _livro)
        magias.push_back(magia.get_nome());

    return magias;
}

int Grimorio::get_num_magias(){
    return _livro.size();
}
