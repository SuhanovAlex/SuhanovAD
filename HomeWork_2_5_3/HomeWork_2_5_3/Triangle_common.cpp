#include "Triangle_common.h"

    unsigned int Triangle_common::get_side_a() {
        return side_a;
    };
    unsigned int Triangle_common::get_side_b() {
        return side_b;
    };
    unsigned int Triangle_common::get_side_c() {
        return side_c;
    };
    unsigned int Triangle_common::get_corner_A() {
        return corner_A;
    };
    unsigned int Triangle_common::get_corner_B() {
        return corner_B;
    };
    unsigned int Triangle_common::get_corner_C() {
        return corner_C;
    };
    /*virtual*/ bool Triangle_common::check() {
        if ((side_a == 0) || (side_b == 0) || (side_c == 0) || (corner_A + corner_B + corner_C) != 180) return false;
        else return true;
    };
    void Triangle_common::print_info() /*override*/ {
        Figure::print_info();
        if (check()) std::cout << "Правильная." << std::endl;
        else std::cout << "Неправильная." << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_corner_A() << " B=" << get_corner_B() << " C=" << get_corner_C() << std::endl << std::endl;
    };

    Triangle_common::Triangle_common() : Figure(3, "Треугольник")
    {};
    Triangle_common::Triangle_common(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B, unsigned int corner_C) : Figure(3, "Треугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        this->corner_C = corner_C;
    };
