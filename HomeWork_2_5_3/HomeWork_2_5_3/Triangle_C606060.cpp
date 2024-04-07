#include "Triangle_C606060.h"


Triangle_C606060::Triangle_C606060(unsigned int side_a) : Triangle_common(side_a, side_a, side_a, 60, 60, 60)
{
    sides_count = 3;
    name = "Равносторонний треугольник";
};
    bool Triangle_C606060::check() /*override*/ {
        if (!Triangle_common::check()) return false;
        else return true;
    };
