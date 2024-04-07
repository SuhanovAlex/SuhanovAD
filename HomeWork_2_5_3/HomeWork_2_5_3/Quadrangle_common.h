#pragma once
#include "Figure.h"

class Quadrangle_common : public Figure
{
protected:
    unsigned int side_a;
    unsigned int side_b;
    unsigned int side_c;
    unsigned int side_d;
    unsigned int corner_A;
    unsigned int corner_B;
    unsigned int corner_C;
    unsigned int corner_D;
public:
    unsigned int get_side_a();
    unsigned int get_side_b();
    unsigned int get_side_c();
    unsigned int get_side_d();
    unsigned int get_corner_A();
    unsigned int get_corner_B();
    unsigned int get_corner_C();
    unsigned int get_corner_D();

    virtual bool check();

    void print_info() override;
    Quadrangle_common();
    Quadrangle_common(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};