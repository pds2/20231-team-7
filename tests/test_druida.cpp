#include "../third_party/doctest.h"
#include "../include/herois/druida.h"


TEST_CASE("testa transformacao"){
    Druida d("d",1,10);
    CHECK_THROWS_AS(d.transformar(Humano),nao_pode_transformar_para_transformacao_atual_e);
    CHECK_EQ(d.get_tranformacao(),Humano);
    d.transformar(Urso);
    CHECK_EQ(d.get_tranformacao(),Urso);
    CHECK_EQ(d.get_vida(),6);
    d.transformar(Falcao);
    CHECK_EQ(d.get_tranformacao(),Falcao);
    CHECK_EQ(d.get_vida(),2);
    d.transformar(Lobo);
    CHECK_EQ(d.get_tranformacao(),Lobo);
    CHECK_EQ(d.get_vida(),4);
    d.recebe_dano(1);
    d.transformar(Humano);
    CHECK_EQ(d.get_tranformacao(),Humano);
    CHECK_EQ(d.get_vida(),1);
}

TEST_CASE("testa ataque humano") {
    Druida *d = new Druida("d", 10, 8);
    Druida *p1 = new Druida("p1", 12, 5);

    CHECK_THROWS_AS(d->ataque(0,-1, {p1}), valor_dado_negativo_e);
    CHECK_THROWS_AS(d->ataque(0,-1, {d}), personagem_ataca_a_si_mesmo_e);
    d->ataque(1,2, {p1});
    CHECK_EQ(p1->get_vida(), 6);

    delete d;
    delete p1;
}

TEST_CASE("testa ataque urso") {
    Druida *d = new Druida("d", 10, 8);
    Druida *p1 = new Druida("p1", 12, 5);
    
    CHECK_THROWS_AS(d->ataque(1, -1, {p1}), valor_dado_negativo_e);
    CHECK_THROWS_AS(d->ataque(1, -1, {d}), personagem_ataca_a_si_mesmo_e);
    d->transformar(Urso);
    d->ataque(1, 2, {p1});
    CHECK_EQ(p1->get_vida(), 4);

    delete d;
    delete p1;
}

TEST_CASE("testa ataque falcao") {
    Druida *d = new Druida("d", 10, 8);
    Druida *p1 = new Druida("p1", 12, 5);
    Druida *p2 = new Druida("p2", 12, 5);
    Druida *p3 = new Druida("p3", 12, 5);

    CHECK_THROWS_AS(d->ataque(1, -1, {p1,p2,p3}), valor_dado_negativo_e);
    CHECK_THROWS_AS(d->ataque(1, -1, {d,p3,p2}), personagem_ataca_a_si_mesmo_e);
    d->transformar(Falcao);
    d->ataque(1, 2, {p1,p2,p3});
    CHECK_EQ(p1->get_vida(), 6);
    CHECK_EQ(p2->get_vida(), 6);
    CHECK_EQ(p3->get_vida(), 6);

    delete d;
    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("testa ataque lobo") {
    Druida *d = new Druida("d", 10, 8);
    Druida *p1 = new Druida("p1", 12, 5);
    Druida *p2 = new Druida("p2", 12, 5);

    CHECK_THROWS_AS(d->ataque(1, -1, {p1,p2}), valor_dado_negativo_e);
    CHECK_THROWS_AS(d->ataque(1, -1, {d,p2}), personagem_ataca_a_si_mesmo_e);
    d->transformar(Lobo);
    d->ataque(1, 2, {p1,p2});
    CHECK_EQ(p1->get_vida(), 5);
    CHECK_EQ(p2->get_vida(), 5);

    delete d;
    delete p1;
    delete p2;
}
