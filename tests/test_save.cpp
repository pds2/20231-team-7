#include "../third_party/doctest.h"
#include "../include/sistema.h"

TEST_CASE("save"){
    Sistema sis;
    Druida d("d",10,10);
    Paladino p("p",10,10);
    Guerreiro g("g",10,10);
    Mago m("m",10,10);
    CHECK_THROWS_AS(sis.salva_jogo(4,d,p, 1),slot_invalido_e());
    d.transformar(Falcao);
    d.ataque(p,g,m,3);
    sis.salva_jogo(1,d,p,2);
    p.ganha_exp(249);
    g.ganha_exp(105);
    p.magia_cura(g,1);
    sis.salva_jogo(2,p,g,3);
}
