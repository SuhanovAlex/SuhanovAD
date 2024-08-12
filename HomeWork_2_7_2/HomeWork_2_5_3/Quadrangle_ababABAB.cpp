#include "Quadrangle_ababABAB.h"


Quadrangle_ababABAB::Quadrangle_ababABAB(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Quadrangle_common(side_a, side_b, side_a, side_b, corner_A, corner_B, corner_A, corner_B)
{
    sides_count = 4;
    name = "ֿאנאככוכמדנאלל";
};
bool Quadrangle_ababABAB::check() /*override*/ {
    if (!Quadrangle_common::check() || (side_a == side_b) || (corner_A == corner_B)) return false;
    else return true;
};
