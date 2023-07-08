#include <iostream>

#include "../include/sistema.h"
#include "../include/herois/paladino.h"
#include "../include/herois/druida.h"
#include "../include/herois/guerreiro.h"
#include "../include/herois/mago/mago.h"

using namespace std;

int main()
{
    Sistema *sistema = new Sistema();
    sistema->inicia_menu();

    return 0;
}
