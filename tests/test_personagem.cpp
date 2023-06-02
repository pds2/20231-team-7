#include "../third_party/doctest.h"
#include "../include/personagem.h"

TEST_CASE("testa recebe_dano casos negativo") {
    Personagem p("");
    CHECK_THROWS_AS(p.recebe_dano(-1), dano_negativo_e);
    CHECK_THROWS_AS(p.recebe_dano(0), dano_negativo_e);
    CHECK_THROWS_AS(p.recebe_dano(-20), dano_negativo_e);
}

TEST_CASE("testa aumenta_nivel") {
    Personagem p("");
    CHECK_EQ(p.get_nivel(), 1);
    p.aumenta_nivel();
    CHECK_EQ(p.get_nivel(), 2);
}

TEST_CASE("testa a se o personagem morre") {
    Personagem p("");
    CHECK_EQ(p.morto(), false);
    p.recebe_dano(1);
    CHECK_EQ(p.morto(), true);
}
