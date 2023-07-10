#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/combate.h"
#include "../include/herois/time_heroi.h"
#include "../include/rolar_dados.h"
#include "../include/verifica_opcao.h"

#include <algorithm>

using namespace std;

bool verifica_monstros(vector<Monstro *> monstros){
    unsigned mortos = 0;
    for(auto m: monstros)
        if(m->morto()) mortos++;

    return(mortos == monstros.size());
}

void completa_hud_monstro(int tam){
    if(tam == 3)
        cout << "|" << endl;
    else{
        for(int i = 0; i < (3-tam); i++)
            cout << "| " << string(23, ' ');
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
    h1->set_posicao(1, 1);

    Heroi *h2 = _time.get_h2();
    h2->set_posicao(1, 2);

    for(unsigned i = 0; i < _monstros.size(); i++)
        _monstros.at(i)->set_posicao(4, i+1);
}

void Combate::hud_monstro(){
    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| "  << left << setw(25) << setfill(' ') << _monstros.at(i)->get_nome();
    }
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| Vida: " << left << setw(2) << setfill(' ');
        (_monstros.at(i)->get_vida() == 0) ? cout << termcolor::red << setw(2) << setfill(' ')
        << _monstros.at(i)->get_vida() << termcolor::reset
        : cout << _monstros.at(i)->get_vida();
        cout << string(16, ' ') << right;
    }
    cout << " ";
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++)
        cout << "| Dano: " << setw(2) << setfill(' ') << _monstros.at(i)->get_dano() << string(16, ' ') << right;
    cout << " ";
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        Posicao posicao;
        posicao = _monstros.at(i)->get_posicao();
        cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(12, ' ');
    }
    cout << " ";
    completa_hud_monstro(_monstros.size());

    cout << string(80, '-') << endl; 
}

bool imprime_letra(Heroi* h, Heroi* h1, vector<Monstro *> _m, int l, int c){
    if(h->get_posicao().get_x() == c && h->get_posicao().get_y() == l){ 
        cout << termcolor::green << h->get_letra() << termcolor::reset << " ";
        return true;
    }
    if(h1->get_posicao().get_x() == c && h1->get_posicao().get_y() == l){ 
        cout << termcolor::green << h1->get_letra() << termcolor::reset << " ";
        return true;
    }

    for(auto m: _m){
        if(m->get_posicao().get_x() == c && m->get_posicao().get_y() == l){ 
            cout << termcolor::red << "M" << termcolor::reset << " ";
            return true;
        }
    }

    return false;
}

struct ComparadorDado {
    bool operator()(Personagem* p1, Personagem* p2){
        if(p1->get_dado() == p2->get_dado()) return p1->get_dano() > p2->get_dano();

        return p1->get_dado() > p2->get_dado();
    }
};

void Combate::organiza_ordem(){
    sort(_ordem_combate.begin(), _ordem_combate.end(), ComparadorDado());
}

void Combate::desenha_tabuleiro(){
    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();
    
    cout << termcolor::blue << "TABULEIRO: " << termcolor::reset << endl;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 4; j++){
            if(imprime_letra(h1, h2, _monstros, i, j)) continue;
            cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

void mostra_habilidades(Heroi* h){
    Escolhe_ataque e(h);
    unsigned op = e.retorna_opcao();
    int a; cin >> a;
}

void Combate::desenha_hud(){
    system("clear");
    _time.desenha_hud();
    hud_monstro();
    desenha_tabuleiro();
}



void Combate::rola_dados(){
    Rolar_Dados *dados = new Rolar_Dados();

    cout << "Dados para decidir ordem (d20): ";
    for(auto p: _ordem_combate){
        int dado = dados->rolar_d20();
        cout << p->get_nome() << ":" << dado << "  ";
        p->set_dado(dado);
    }
    cout << endl;
    organiza_ordem();

    cout << "ordem combate: ";
    for(auto p: _ordem_combate) cout << p->get_nome() << " ";
    cout << "\n\n";

    mostra_habilidades(_time.get_h1());
    cout << endl;
    mostra_habilidades(_time.get_h2());
    cout << endl;

    delete dados;
}

bool Combate::entra_combate(vector<Monstro *> monstros){
    _monstros = monstros;

    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();

    seta_posicoes();

    bool player_venceu = false;
    while(h1->morto() == false || h2->morto() == false)
    {
        _ordem_combate = {h1, h2};
        for(auto m: _monstros) _ordem_combate.push_back(m);
        desenha_hud();
        rola_dados();
        break;
        /*
        h1->recebe_dano(4);
        sleep(1);
        cout.flush();
        desenha_hud();
        h2->recebe_dano(4);
        sleep(1);
        cout.flush();
        desenha_hud();
        for(auto m: _monstros){
            m->recebe_dano(9);
            sleep(1);
            cout.flush();
            desenha_hud();
        }*/

        system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

        player_venceu = verifica_monstros(_monstros);
        if(player_venceu) break;
    }

    desenha_hud();
    system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

    return player_venceu;
}
