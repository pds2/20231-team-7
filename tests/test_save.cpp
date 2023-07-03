#include "../third_party/doctest.h"
#include "../include/herois/druida.h"
#include "../include/herois/paladino.h"
#include "../include/herois/guerreiro.h"
#include "../include/herois/mago/mago.h"
#include "../include/sistema.h"

TEST_CASE("save"){
    Sistema *sis = new Sistema();
    Druida *d = new Druida("d",10,10);
    Paladino *p = new Paladino("p",10,10);
    Guerreiro *g = new Guerreiro("g",10,10);
    Mago *m = new Mago("m",10,10);
    

    CHECK_THROWS_AS(sis->salva_jogo(4,*d,*p, 1),slot_invalido_e);

    d->transformar(Falcao);
    CHECK(1==2);
    d->ataque(2, {p,g,m});
    CHECK(1==2);
    sis->salva_jogo(1,*d,*p,2);
    CHECK(1==2);
    p->ganha_exp(249);
    CHECK(1==2);
    g->ganha_exp(105);
    CHECK(1==2);
    p->magia_cura(*g,1);
    CHECK(1==2);
    sis->salva_jogo(2,*p,*g,3);
    CHECK(1==2);

    delete sis;
    delete d;
    delete p;
    delete g;
    delete m;
}
