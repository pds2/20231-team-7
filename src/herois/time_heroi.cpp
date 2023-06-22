#include <iomanip>

#include "../../include/herois/time_heroi.h"

using namespace std;

Time_h::Time_h() {}

Time_h::Time_h(Heroi& h1, Heroi& h2){
    _time.first = &h1;
    _time.second = &h2;
}

Time_h::~Time_h(){
    delete _time.first;
    delete _time.second;
}

Heroi* Time_h::get_h1(){
    return _time.first;
}

void Time_h::set_h1(Heroi& h1){
    _time.first = &h1;
}

Heroi* Time_h::get_h2(){
    return _time.second;
}

void Time_h::set_h2(Heroi& h2){
    _time.second = &h2;
}

void Time_h::desenha_hud(){
    cout << "| " << left << setw(12) << setfill(' ') << _time.first->get_nome() << string(19, ' ')
         << "Nível: " << _time.first->get_nivel() << " | "
         << setw(12) << setfill(' ') << _time.second->get_nome() << string(19, ' ') << right
         << "Nível: " << _time.second->get_nivel() << " |" << endl

         << "| Vida: " << setw(2) << setfill('0') << _time.first->get_vida() << string(32, ' ') << "| "
         << "Vida: " << setw(2) << setfill('0') << _time.second->get_vida() << string(32, ' ') << "|" << endl
         
         << "| Dano: " << setw(2) << setfill('0') << _time.first->get_dano() << string(32, ' ')<< "| "
         << "Dano: " << setw(2) << setfill('0') << _time.second->get_dano() << string(32, ' ')<< "|" << endl;

    Posicao posicao;
    posicao = _time.first->get_posicao();
    cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(28, ' ') << "| ";

    posicao = _time.second->get_posicao();
    cout << "Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(28, ' ') << "|" << endl;

    cout << string(85, '-') << endl;
}
