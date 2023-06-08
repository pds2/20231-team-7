#include "../third_party/doctest.h"
#include "../include/druida.h"


TEST_CASE("testa transformacao"){
    Druida d("d",1,1,10);
    CHECK_THROWS_AS(d.transformar(Humano),nao_pode_transformar_para_transformacao_atual_e);
    CHECK_EQ(d.get_tranformacao(),Humano);
    d.transformar(Urso);
    CHECK_EQ(d.get_tranformacao(),Urso);
    d.transformar(Falcao);
    CHECK_EQ(d.get_tranformacao(),Falcao);
    d.transformar(Lobo);
    CHECK_EQ(d.get_tranformacao(),Lobo);
    d.transformar(Humano);
    CHECK_EQ(d.get_tranformacao(),Humano);
}

TEST_CASE("testa ataque humano") {
    Druida d("d", 10, 8,10);
    Personagem p1("p1", 12, 5);
    Personagem p2("p2", 12, 5);
    Personagem p3("p3", 12, 5);
    CHECK_THROWS_AS(d.ataque(p1,p2,p3, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(d.ataque(d,p3,p2, -1), personagem_ataca_a_si_mesmo_e);
    d.ataque(p1,p2,p3,2);
    CHECK_EQ(p1.get_vida(), 6);
    CHECK_EQ(p3.get_vida(), 12);
    CHECK_EQ(p2.get_vida(), 12);
}
TEST_CASE("testa ataque urso") {
    Druida d("d", 10, 8,10);
    Personagem p1("p1", 12, 5);
    Personagem p2("p2", 12, 5);
    Personagem p3("p3", 12, 5);
    CHECK_THROWS_AS(d.ataque(p1,p2,p3, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(d.ataque(d,p3,p2, -1), personagem_ataca_a_si_mesmo_e);
    d.transformar(Urso);
    d.ataque(p1,p2,p3, 2);
    CHECK_EQ(p1.get_vida(), 4);
    CHECK_EQ(p3.get_vida(), 12);
    CHECK_EQ(p2.get_vida(), 12);
}

TEST_CASE("testa ataque falcao") {
    Druida d("d", 10, 8,10);
    Personagem p1("p1", 12, 5);
    Personagem p2("p2", 12, 5);
    Personagem p3("p3", 12, 5);
    CHECK_THROWS_AS(d.ataque(p1,p2,p3, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(d.ataque(d,p3,p2, -1), personagem_ataca_a_si_mesmo_e);
    d.transformar(Falcao);
    d.ataque(p1,p2,p3, 2);
    CHECK_EQ(p1.get_vida(), 6);
    CHECK_EQ(p2.get_vida(), 6);
    CHECK_EQ(p3.get_vida(), 6);
}

TEST_CASE("testa ataque lobo") {
    Druida d("d", 10, 8,10);
    Personagem p1("p1", 12, 5);
    Personagem p2("p2", 12, 5);
    Personagem p3("p3", 12, 5);
    CHECK_THROWS_AS(d.ataque(p1,p2,p3, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(d.ataque(d,p3,p2, -1), personagem_ataca_a_si_mesmo_e);
    d.transformar(Lobo);
    d.ataque(p1,p2,p3, 2);
    CHECK_EQ(p1.get_vida(), 5);
    CHECK_EQ(p2.get_vida(), 5);
    CHECK_EQ(p3.get_vida(), 12);
}
