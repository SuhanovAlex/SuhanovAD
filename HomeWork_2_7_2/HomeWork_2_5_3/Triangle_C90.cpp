#include "Triangle_C90.h"

Triangle_C90::Triangle_C90(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_c, corner_A, corner_B, 90)
{
    sides_count = 3;
    name = "Прямоугольный треугольник";
};

    bool Triangle_C90::check() /*override*/ {
        if (!Triangle_common::check() || (corner_A == 90) || (corner_B == 90)) return false;
        else return true;
    };
