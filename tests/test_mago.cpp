#include "../third_party/doctest.h"
#include "../include/herois/mago/mago.h"

TEST_CASE("testa aumenta_nivel") {
    Mago *p = new Mago("p", 10, 10);

    CHECK_EQ(p->get_num_habilidades(), 2);
    CHECK_EQ(p->get_nivel(), 1);
    CHECK_EQ(p->get_vida(), 10);
    CHECK_EQ(p->get_mana(),12);
    p->ganha_exp(101);
    CHECK_EQ(p->get_num_habilidades(), 3);
    CHECK_EQ(p->get_nivel(), 2);
    CHECK_EQ(p->get_vida(), 13);
    CHECK_EQ(p->get_mana(), 15);
    p->ganha_exp(50);
    CHECK_EQ(p->get_nivel(), 2);
    CHECK_EQ(p->get_dano(), 13);
    CHECK_EQ(p->get_mana(), 15);

    delete p;
}
//4 18 12 32
TEST_CASE("MAGIAS"){
    Mago *p = new Mago("p", 10, 10);
    Mago *p1 = new Mago("p1", 200, 10);

    p->lança_magia(1,2,{p1});
    CHECK_EQ(p1->get_vida(),192);
    p->lança_magia(2,2,{p1});
    CHECK_EQ(p1->get_vida(),170);
    p->ganha_exp(101);
    p->lança_magia(3,2,{p1});
    CHECK_EQ(p1->get_vida(),154);
    p->ganha_exp(101);
    p->lança_magia(4,2,{p1});
    CHECK_EQ(p1->get_vida(),118);
    p->lança_magia(3,2,{p1});
    CHECK_THROWS(p->lança_magia(4,2,{p1}), mana_insuficiente_e());

    delete p;
    delete p1;

}