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
// PLACEHOLDER,DRUIDA, GUERREIRO, MAGO, PALADINO
string string_classe(Classes classe){
    switch(classe){
        case 1:
            return "Druida";
        case 2:
            return "Guerreiro";
        case 3:
            return "Mago";
        case 4:
            return "Paladino";
        default:
            return "";
    }
}

void Time_h::reseta_time(){
    _time.first->set_vida(_time.first->get_vida_max());
    _time.second->set_vida(_time.second->get_vida_max());
}

void Time_h::desenha_hud(){
    cout << "| " << termcolor::blue << left << setw(27) << setfill(' ') << _time.first->get_nome() 
         << termcolor::reset
         << "Nível: " << _time.first->get_nivel() << " | "
         << termcolor::blue << setw(27) << setfill(' ') << _time.second->get_nome() << right << termcolor::reset
         << "Nível: " << _time.second->get_nivel() << " |" << endl

         << "| Vida: ";
         (_time.first->get_vida() == 0) ? cout << termcolor::red << left << setw(20) << setfill(' ') << _time.first->get_vida() << termcolor::reset
         : cout << left << setw(20) << setfill(' ') << _time.first->get_vida();
         cout << right << setw(9) << setfill(' ') << string_classe(_time.first->get_classe()) << " | "

         << "Vida: ";
         (_time.second->get_vida() == 0) ? cout << termcolor::red << left << setw(20) << setfill(' ') << _time.second->get_vida() << termcolor::reset
         : cout << left << setw(20) << setfill(' ') << _time.second->get_vida();
         cout << right << setw(9) << setfill(' ') << string_classe(_time.second->get_classe()) << " | " << endl
         
         << "| Dano: " << left << setw(30) << setfill(' ') << _time.first->get_dano() << "| "
         << "Dano: " << setw(30) << setfill(' ') << _time.second->get_dano() << right << "|" << endl;

    Posicao posicao;
    posicao = _time.first->get_posicao();
    cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(24, ' ') << "| ";

    posicao = _time.second->get_posicao();
    cout << "Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(24, ' ') << "|" << endl;

    cout << string(77, '-') << endl;
}
