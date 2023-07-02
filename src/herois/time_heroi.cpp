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
    cout << "| " << termcolor::blue << left << setw(12) << setfill(' ') << _time.first->get_nome()
         << string(16, ' ') << termcolor::reset
         << "Nível: " << _time.first->get_nivel() << " | "
         << termcolor::blue << setw(12) << setfill(' ') << _time.second->get_nome() << string(16, ' ') << right
         << termcolor::reset
         << "Nível: " << _time.second->get_nivel() << " |" << endl

         << "| Vida: " << left << setw(2) << setfill(' ');
         (_time.first->get_vida() == 0) ? cout << termcolor::red << left << setw(2) << setfill(' ') << _time.first->get_vida() << termcolor::reset
         : cout << _time.first->get_vida();
         cout << string(29, ' ') << "| "

         << "Vida: " << setw(2) << setfill(' ');
         (_time.second->get_vida() == 0) ? cout << termcolor::red << setw(2) << setfill(' ') << _time.second->get_vida() << termcolor::reset
         : cout << _time.second->get_vida();
         cout << string(29, ' ') << right << "|" << endl
         
         << "| Dano: " << setw(2) << setfill(' ') << _time.first->get_dano() << string(29, ' ')<< "| "
         << "Dano: " << setw(2) << setfill(' ') << _time.second->get_dano() << string(29, ' ')<< "|" << endl;

    Posicao posicao;
    posicao = _time.first->get_posicao();
    cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(25, ' ') << "| ";

    posicao = _time.second->get_posicao();
    cout << "Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(25, ' ') << "|" << endl;

    cout << string(79, '-') << endl;
}
