#include "Quadrangle_common.h"


    unsigned int Quadrangle_common::get_side_a() {
        return side_a;
    };
    unsigned int Quadrangle_common::get_side_b() {
        return side_b;
    };
    unsigned int Quadrangle_common::get_side_c() {
        return side_c;
    };
    unsigned int Quadrangle_common::get_side_d() {
        return side_d;
    };
    unsigned int Quadrangle_common::get_corner_A() {
        return corner_A;
    };
    unsigned int Quadrangle_common::get_corner_B() {
        return corner_B;
    };
    unsigned int Quadrangle_common::get_corner_C() {
        return corner_C;
    };
    unsigned int Quadrangle_common::get_corner_D() {
        return corner_D;
    };

    /*virtual*/ bool Quadrangle_common::check() {
        if ((side_a == 0) || (side_b == 0) || (side_c == 0) || (side_d == 0) || (corner_A + corner_B + corner_C + corner_D) != 360) return false;
        else return true;
    };

    void Quadrangle_common::print_info() /*override*/ {
        Figure::print_info();
        if (check()) std::cout << "Правильная." << std::endl;
        else std::cout << "Неправильная." << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_corner_A() << " B=" << get_corner_B() << " C=" << get_corner_C() << " D=" << get_corner_D() << std::endl << std::endl;

    };
    Quadrangle_common::Quadrangle_common() : Figure(4, "Четырехугольник")
    {};
    Quadrangle_common::Quadrangle_common(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int side_d, unsigned int corner_A, unsigned int corner_B, unsigned int corner_C, unsigned int corner_D) : Figure(4, "Четырехугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        this->corner_C = corner_C;
        this->corner_D = corner_D;
    };
