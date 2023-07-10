#include "../third_party/doctest.h"
#include "../include/herois/guerreiro.h"

TEST_CASE("testa ataque") {
    Guerreiro *p = new Guerreiro("p", 10, 8);
    Guerreiro *p1 = new Guerreiro("p1", 12, 5);
    CHECK_THROWS_AS(p->ataque(-1, {p1}), valor_dado_negativo_e);
    CHECK_THROWS_AS(p->ataque(-1, {p}), personagem_ataca_a_si_mesmo_e);
    p->ataque(2, {p1});
    CHECK_EQ(p1->get_vida(), 2);
    p->ataque(2, {p1});
    CHECK_EQ(p1->morto(), true);
    
    delete p;
    delete p1;
}

TEST_CASE("testa aumenta_nivel") {
    Guerreiro *p = new Guerreiro("p", 10, 10);
    CHECK_EQ(p->get_nivel(), 1);
    CHECK_EQ(p->get_vida(), 10);
    p->ganha_exp(101);
    CHECK_EQ(p->get_nivel(), 2);
    CHECK_EQ(p->get_vida(), 13);
    CHECK(p->get_habilidades().at(1)=="furia");
    p->ganha_exp(50);
    CHECK_EQ(p->get_nivel(), 2);
    CHECK_EQ(p->get_dano(), 13);

    delete p;
}

TEST_CASE("furia"){
    Guerreiro *g= new Guerreiro("g",10,10);
    Guerreiro *g1= new Guerreiro("g1",50,10);

    g->ataque(2,{g1});
    CHECK_EQ(g1->get_vida(),38);
    CHECK(g->get_furia()==false);
    g->ativa_furia();
    CHECK(g->get_furia()==true);
    CHECK_THROWS(g->ativa_furia(),furia_ja_ativa_e());
    g->ataque(2,{g1});
    CHECK_EQ(g1->get_vida(),14);
    CHECK(g->get_furia()==false);
    
    delete g;
    delete g1;
}