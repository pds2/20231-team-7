#include <iostream>
#include <iomanip>

#include "../include/combate.h"
#include "../include/herois/time_heroi.h"

using namespace std;

bool verifica_monstros(vector<Monstro *> monstros){
    unsigned mortos = 0;
    for(auto m: monstros)
        if(m->morto()) mortos++;

    return(mortos == monstros.size());
}

void completa_hud_monstro(unsigned tam){
    if(tam == 3)
        cout << "|" << endl;
    else{
        for(unsigned i = 0; i < (3-tam); i++)
            cout << "|" << string(25, ' ');
        cout << "|" << endl;
    }
}

Combate::Combate(
    Time_h &time
): _time(time) {}

Combate::~Combate(){
    for(auto m: _monstros)
        delete m;
}

void Combate::seta_posicoes(){
    Heroi *h1 = _time.get_h1();
    h1->set_posicao(0, 0);

    Heroi *h2 = _time.get_h2();
    h2->set_posicao(0, 1);

    for(unsigned i = 0; i < _monstros.size(); i++)
        _monstros.at(i)->set_posicao(4, i);
}

void Combate::hud_monstro(){
    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| " << termcolor::red << left << setw(12) << setfill(' ') << _monstros.at(i)->get_nome()
             << string(12, ' ') << right << termcolor::reset;
    }
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| Vida: " << left << setw(2) << setfill(' ');
        (_monstros.at(i)->get_vida() == 0) ? cout << termcolor::red << setw(2) << setfill(' ')
        << _monstros.at(i)->get_vida() << termcolor::reset
        : cout << _monstros.at(i)->get_vida();
        cout << string(16, ' ') << right;
    }
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++)
        cout << "| Dano: " << setw(2) << setfill(' ') << _monstros.at(i)->get_dano() << string(16, ' ') << right;
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        Posicao posicao;
        posicao = _monstros.at(i)->get_posicao();
        cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(12, ' ');
    }
    completa_hud_monstro(_monstros.size());

    cout << string(79, '-') << endl; 
}

void mostra_habilidades(Heroi* h){
    cout << "Qual ataque " << h->get_nome() << " devera lançar: \n";
    h->print_habilidades();
    cout << "> ";
}

void Combate::desenha_hud(){
    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();

    system("clear");
    _time.desenha_hud();
    hud_monstro();

    string op1;
    int op;
    for(int i = 1; i <= 2; i++){
        mostra_habilidades(h1);
        cout << endl;
        mostra_habilidades(h2);
        cout << endl;

        while(cin >> op1){
            istringstream is(op1);
            is >> op;

            if(op == 1){
                break;
            } else if(op == 2){
                break;
            } else if(op == 3){
                break;
            } else if(op == 4){
                break;
            } else{
            cout << termcolor::red << "Opção inválida. Tente novamente!\n" << termcolor::reset;
            system("read -n 1 -s -r -p 'Aperte qualquer tecla para continuar...'");
            }

            cout << "\n\n";
            cout << "Qual ataque " << h1->get_nome() << " devera lançar: \n";
            h1->print_habilidades();
            cout << "> ";
        }
    }
}

bool Combate::entra_combate(vector<Monstro *> monstros){
    _monstros = monstros;

    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();

    seta_posicoes();

    bool player_venceu = false;
    while(h1->morto() == false || h2->morto() == false)
    {
        desenha_hud();

        h1->recebe_dano(4);
        h2->recebe_dano(4);
        for(auto m: _monstros) m->recebe_dano(9);

        system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

        player_venceu = verifica_monstros(_monstros);
        if(player_venceu) break;
    }

    desenha_hud();
    system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

    return player_venceu;
}
