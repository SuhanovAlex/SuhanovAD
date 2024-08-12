#pragma once
#include "Figure.h"


class Triangle_common : public Figure
{
protected:
    unsigned int side_a;
    unsigned int side_b;
    unsigned int side_c;
    unsigned int corner_A;
    unsigned int corner_B;
    unsigned int corner_C;

public:
    unsigned int get_side_a();
    unsigned int get_side_b();
    unsigned int get_side_c();
    unsigned int get_corner_A();
    unsigned int get_corner_B();
    unsigned int get_corner_C();
    virtual bool check();
    void print_info() override;
    int TriangleCheckSidesAreZero(unsigned int, unsigned int, unsigned int);

    Triangle_common();
    Triangle_common(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};