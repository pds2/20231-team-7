#include "../third_party/doctest.h"
#include "../include/heroi.h"

TEST_CASE("testa ganha_exp casos negativo") {
    Heroi p("", 10, 10, "");
    CHECK_THROWS_AS(p.ganha_exp(-1), impossivel_adicionar_exp_negativa_e);
    CHECK_THROWS_AS(p.ganha_exp(0), impossivel_adicionar_exp_negativa_e);
    CHECK_THROWS_AS(p.ganha_exp(-20), impossivel_adicionar_exp_negativa_e);
}

TEST_CASE("testa aumenta_nivel") {
    Heroi p("", 10, 10, "");
    CHECK_EQ(p.get_nivel(), 1);
    CHECK_EQ(p.get_vida(), 10);
    p.ganha_exp(101);
    CHECK_EQ(p.get_nivel(), 2);
    CHECK_EQ(p.get_vida(), 13);
    p.ganha_exp(50);
    CHECK_EQ(p.get_nivel(), 2);
    CHECK_EQ(p.get_dano(), 13);
}

TEST_CASE("testa adicionar_habilidade casos iguais") {
    Heroi p("", 10, 10, "");
    p.adiciona_habilidade("feitico_fogo");
    CHECK_THROWS_AS(p.adiciona_habilidade("feitico_fogo"), habilidade_ja_existe_e);
}

TEST_CASE("testa desbloquear_habilidades casos que habilidade nao existe") {
    Heroi p("", 10, 10, "");
    CHECK_THROWS_AS(p.desbloqueia_habilidade("feitico_fogo"), habilidade_nao_existe_e);
}

