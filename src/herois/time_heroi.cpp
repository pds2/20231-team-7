#include "../../include/herois/time_heroi.h"

Time_h::Time_h(Heroi& h1, Heroi& h2){
    _time.first = &h1;
    _time.second = &h2;
}
