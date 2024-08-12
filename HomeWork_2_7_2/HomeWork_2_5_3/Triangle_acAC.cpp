#include "Triangle_acAC.h"


Triangle_acAC::Triangle_acAC(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_a, corner_A, corner_B, corner_A)
{
    sides_count = 3;
    name = "Равнобедренный треугольник";
};

    bool Triangle_acAC::check() /*override*/ {
        if (!Triangle_common::check() || (side_a == side_b) || (corner_A == corner_B)) return false;
        else return true;
    };
