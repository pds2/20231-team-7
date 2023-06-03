#include "../third_party/doctest.h"
#include "../include/personagem.h"

TEST_CASE("testa recebe_dano") {
    Personagem p("p", 10, 10);
    CHECK_THROWS_AS(p.recebe_dano(-1), dano_negativo_e);
    CHECK_THROWS_AS(p.recebe_dano(0), dano_negativo_e);
    p.recebe_dano(3);
    CHECK_EQ(p.get_vida(), 7);
}

TEST_CASE("testa ataque") {
    Personagem p("p", 10, 8);
    Personagem p1("p1", 12, 5);
    CHECK_THROWS_AS(p.ataque(p1, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(p.ataque(p, -1), personagem_ataca_a_si_mesmo_e);
    p.ataque(p1, 2);
    CHECK_EQ(p1.get_vida(), 6);
    p1.ataque(p, 6);
    CHECK_EQ(p.get_vida(), 2);
    p.ataque(p1, 3);
    CHECK_EQ(p1.morto(), true);
}

TEST_CASE("testa aumenta_nivel") {
    Personagem p("p", 10, 10);
    CHECK_EQ(p.get_nivel(), 1);
    p.aumenta_nivel();
    CHECK_EQ(p.get_nivel(), 2);
}

TEST_CASE("testa se o personagem morre") {
    Personagem p("p", 10, 10);
    CHECK_EQ(p.morto(), false);
    p.recebe_dano(1);
    CHECK_EQ(p.morto(), false);
    p.recebe_dano(10);
    CHECK_EQ(p.morto(), true);
}
