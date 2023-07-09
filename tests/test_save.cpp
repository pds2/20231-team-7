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
    

 

    
    delete sis;
    delete d;
    delete p;
    delete g;
    delete m;
}
