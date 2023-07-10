#include "../third_party/doctest.h"
#include "../include/monstros/cao_infernal.h"
#include "../include/monstros/dao.h"
#include "../include/monstros/golem_de_carne.h"
#include "../include/monstros/pantera_deslocadora.h"


TEST_CASE("ataque"){
    Monstro *c= new CaoInfernal();
    Monstro *d= new Dao();
    Monstro *g= new Golem_de_carne();
    Monstro *p= new PanteraDeslocadora();

    Monstro *m= new Golem_de_carne();
    c->ataque(3,{m});
    CHECK_EQ(m->get_vida(), 86);
    d->ataque(3,{m});
    CHECK_EQ(m->get_vida(), 74);
    g->ataque(3,{m});
    CHECK_EQ(m->get_vida(), 65);
    p->ataque(3,{m});
    CHECK_EQ(m->get_vida(), 56);


    delete c;
    delete d;
    delete g;
    delete p;
    delete m;
}