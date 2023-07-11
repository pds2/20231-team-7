#include <iostream>
#include <iomanip>
#include <vector>

#include "../include/herois/guerreiro.h"
#include "../include/combate.h"
#include "../include/herois/time_heroi.h"
#include "../include/herois/druida.h"
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
        cout << " |" << endl;
    else{
        for(int i = 0; i < (3-tam); i++)
            cout << "| " << string(24, ' ');
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
        cout << "| "  << termcolor::red << left << setw(23) << setfill(' ') << _monstros.at(i)->get_nome()
             << right << termcolor::reset;
    }
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        cout << "| Vida: ";
        (_monstros.at(i)->get_vida() == 0) ? cout << termcolor::red << left << setw(17) << setfill(' ')
        << _monstros.at(i)->get_vida() << termcolor::reset
        : cout << left << setw(17) << setfill(' ') << _monstros.at(i)->get_vida();
        cout << right;
    }
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++)
        cout << "| Dano: " << left << setw(17) << setfill(' ') << _monstros.at(i)->get_dano() << right;
    completa_hud_monstro(_monstros.size());

    for(unsigned i = 0; i < _monstros.size(); i++){
        Posicao posicao;
        posicao = _monstros.at(i)->get_posicao();
        cout << "| Posicao: " << posicao.get_x() << " " << posicao.get_y() << string(11, ' ');
    }
    completa_hud_monstro(_monstros.size());

    cout << string(77, '-') << endl; 
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
            cout << termcolor::red << m->get_letra() << termcolor::reset << " ";
            return true;
        }
    }

    return false;
}

struct ComparadorDado {
    bool operator()(Personagem* p1, Personagem* p2){
        if(p1->get_dado_ordem() == p2->get_dado_ordem()) return p1->get_dano() > p2->get_dano();

        return p1->get_dado_ordem() > p2->get_dado_ordem();
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

void printa_ordem(vector<Personagem *> ordem){
    cout << "Ordem combate (D20): ";
    for(auto p: ordem) cout << p->get_nome() << "(" << p->get_dado_ordem() << ")" << " ";
    cout << "\n";

    cout << "Dano (D06):  ";
    for(auto p: ordem) cout << p->get_nome() << "(" << p->get_dado_dano() << ")" << " ";
    cout << "\n\n";
}

void Combate::desenha_hud(){
    system("clear");
    _time.desenha_hud();
    hud_monstro();
    desenha_tabuleiro();
    printa_ordem(_ordem_combate);
}

void Combate::rola_dados(){
    Rolar_Dados *dados = new Rolar_Dados();
    
    for(auto p: _ordem_combate){
        int dado = dados->rolar_d20();
        p->set_dado_ordem(dado);
    }
    organiza_ordem();

    for(auto p: _ordem_combate){
        int dado = dados->rolar_d06();
        p->set_dado_dano(dado);
    }

delete dados;
}

unsigned mostra_habilidades(Heroi* h){
    Escolhe_ataque e(h);
    return e.retorna_opcao();
}

unsigned mostra_alvos(vector<Personagem *> personagens){
    Escolhe_alvo e(personagens);
    return e.retorna_opcao();
}

pair<unsigned,unsigned> decide_ataque(Heroi* h1, Heroi* h2, vector<Personagem *> p){
    unsigned ataque_h = mostra_habilidades(h1);
    if(ataque_h == h1->get_num_habilidades()+1) 
        return {ataque_h, 0};

    unsigned alvo_h;
    if(h1->get_classe() == 1 && ataque_h == 2){
        Escolhe_transformacao_druida e(h1);
        alvo_h = e.retorna_opcao();
        try{
            faz_transformacao(h1, alvo_h);
        } catch(nao_pode_transformar_para_transformacao_atual_e){
            cout << "Ja é dessa forma" << endl;
        }
        return {ataque_h, alvo_h};
    }
    if(h1->get_classe() == Classes::PALADINO && ataque_h == 1)
        alvo_h = mostra_alvos({h1, h2});
    else
        alvo_h = mostra_alvos(p);

    return {ataque_h, alvo_h};
}

vector<Personagem *> retorna_upcast_m(vector<Monstro *> _m){
    vector<Personagem *> p_monstros;
    for(auto m: _m){
        Personagem *p = m;
        p_monstros.push_back(p);
    }
    return p_monstros;
}

pair<unsigned,unsigned> Combate::ataque_heroi(int n){
    vector<Personagem *> p_monstros = retorna_upcast_m(_monstros);

    if(n == 1)
        return decide_ataque(_time.get_h1(), _time.get_h2(), p_monstros);

    desenha_hud();
    return decide_ataque(_time.get_h2(), _time.get_h1(), p_monstros);
}

void Combate::ataca_na_ordem(Personagem * p, pair<unsigned,unsigned> op1, pair<unsigned,unsigned> op2){
    if(p->eh_heroi()){
        vector<Personagem *> p_monstros = retorna_upcast_m(_monstros);

        if(p->get_letra() == _time.get_h1()->get_letra()){
            try{
                if(op1.second == 0) p->move();
                else try{
                     p->ataque(op1.first, p->get_dado_dano(), {p_monstros.at(op1.second-1)});
                    } catch(mana_insuficiente_e){
                    cout<< "Mana insuficiente!!"<<endl;
                    } catch(furia_ja_ativa_e){
                    cout<< "Furia ja esta ativa insuficiente!!"<<endl;
                    }
            } catch(posicao_invalida_e e){
                cout << "Não pode mais mover para frente." << endl;
            }
        } else{
            try{
                if(op2.second == 0) p->move();
                else try{ p->ataque(op2.first, p->get_dado_dano(), {p_monstros.at(op2.second-1)});
                } catch(mana_insuficiente_e){
                    cout<< "Mana insuficiente!!"<<endl;
                    } catch(furia_ja_ativa_e){
                    cout<< "Furia ja esta ativa insuficiente!!"<<endl;
                    }
            } catch(posicao_invalida_e e){
                cout << "Não pode mais mover para frente." << endl;
            }
        }
    }         
    else try{
        p->ataque(1, p->get_dado_dano(), {_time.get_h1(), _time.get_h2()});
    } catch(mana_insuficiente_e){
        cout<< "Mana insuficiente!!"<<endl;
    } catch(furia_ja_ativa_e){
        cout<< "Furia ja esta ativa insuficiente!!"<<endl;
    }
}

bool Combate::entra_combate(vector<Monstro *> monstros){
    Heroi *h1 = _time.get_h1();
    Heroi *h2 = _time.get_h2();
    _monstros = monstros;
    seta_posicoes();

    bool player_venceu = false;
    pair<unsigned,unsigned> op1;
    pair<unsigned,unsigned> op2;
    while(h1->morto() == false || h2->morto() == false){
        _ordem_combate = {h1, h2};
        for(auto m: _monstros) _ordem_combate.push_back(m);

        rola_dados();
        desenha_hud();

        op1 = ataque_heroi(1);
        op2 = ataque_heroi(2);

        for(auto p: _ordem_combate){
            if(p->morto() == true) continue;
            
            ataca_na_ordem(p, op1, op2);
        }

        player_venceu = verifica_monstros(_monstros);
        if(player_venceu) break;
    }

    desenha_hud();
    system("read -n 1 -s -r -p 'Aperte qualquer tecla para ir para o proximo turno.'");

    return player_venceu;
}
