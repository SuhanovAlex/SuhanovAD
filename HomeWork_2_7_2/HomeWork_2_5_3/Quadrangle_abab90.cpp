#include "Quadrangle_abab90.h"


Quadrangle_abab90::Quadrangle_abab90(unsigned int side_a, unsigned int side_b) : Quadrangle_ababABAB(side_a, side_b, 90, 90)
{
    sides_count = 4;
    name = "Прямоугольник";
};

bool Quadrangle_abab90::check() /*override*/ {
    if (!Quadrangle_common::check() || (side_a == side_b)) return false;
    else return true;
};
