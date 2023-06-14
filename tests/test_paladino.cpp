#include "../third_party/doctest.h"
#include "../include/herois/paladino.h"


TEST_CASE("testa ataque") {
    Paladino p("p", 10, 8);
    Personagem p1("p1", 12, 5);
    CHECK_THROWS_AS(p.ataque(p1, -1), valor_dado_negativo_e);
    CHECK_THROWS_AS(p.ataque(p, -1), personagem_ataca_a_si_mesmo_e);
    p.ataque(p1, 2);
    CHECK_EQ(p1.get_vida(), 5);
    p.ataque(p1, 2);
    CHECK_EQ(p1.morto(), true);
    
}

TEST_CASE("cura aliado"){
    Paladino p("p", 10, 8);
    Heroi p1("p1", 12, 10);
    p1.recebe_dano(10);
    p.magia_cura(p1,5);
    CHECK_EQ(p1.get_vida(),7);
    p.magia_cura(p1,10);
    CHECK_EQ(p1.get_vida(),p1.get_vida_max());
    p.recebe_dano(8);
    p.magia_cura(p,5);
    CHECK_EQ(p.get_vida(),7);
    p.magia_cura(p,10);
    CHECK_EQ(p.get_vida(),p.get_vida_max());
    p.magia_cura(p1,5);
    CHECK_THROWS_AS(p.magia_cura(p,10),mana_insuficiente_e);
}

TEST_CASE("recuperar mana"){
    Paladino p("",10,10);
    p.magia_cura(p,2);
    p.magia_cura(p,2);
    p.recuperar_mana();
    CHECK_EQ(p.get_mana(),8);
    p.recuperar_mana();
    CHECK_EQ(p.get_mana(),10);
}

TEST_CASE("testa aumenta_nivel") {
    Paladino p("", 10, 10);
    CHECK_EQ(p.get_nivel(), 1);
    CHECK_EQ(p.get_vida(), 10);
    CHECK_EQ(p.get_mana(),10);
    p.ganha_exp(101);
    CHECK_EQ(p.get_nivel(), 2);
    CHECK_EQ(p.get_vida(), 13);
    CHECK_EQ(p.get_mana(), 14);
    p.ganha_exp(50);
    CHECK_EQ(p.get_nivel(), 2);
    CHECK_EQ(p.get_dano(), 13);
    CHECK_EQ(p.get_mana(), 14);
}
