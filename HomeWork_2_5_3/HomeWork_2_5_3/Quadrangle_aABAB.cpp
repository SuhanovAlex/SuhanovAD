#include "Quadrangle_aABAB.h"


Quadrangle_aABAB::Quadrangle_aABAB(unsigned int side_a, unsigned int corner_A, unsigned int corner_B) : Quadrangle_ababABAB(side_a, side_a, corner_A, corner_B)
{
    sides_count = 4;
    name = "Ромб";
};

bool Quadrangle_aABAB::check() /*override*/ {
    if (!Quadrangle_common::check() || (corner_A == corner_B)) return false;
    else return true;
};
