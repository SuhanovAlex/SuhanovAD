#include "Quadrangle_a90.h"


Quadrangle_a90::Quadrangle_a90(unsigned int side_a) : Quadrangle_aABAB(side_a, 90, 90)
{
    sides_count = 4;
    name = " вадрат";
};

bool Quadrangle_a90::check() /*override*/ {
    if (!Quadrangle_common::check()) return false;
    else return true;
};
