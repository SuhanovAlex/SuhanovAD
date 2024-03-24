

#include "Figure.h"
#include "Triangle_common.h"
#include "Quadrangle_common.h"
#include <Windows.h>





class Triangle_C90 : public Triangle_common
{
public:
    Triangle_C90(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_c, corner_A, corner_B, 90)
    {
        sides_count = 3;
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        if (!Triangle_common::check() || (corner_A == 90) || (corner_B == 90)) return false;
        else return true;
    };
};

class Triangle_acAC : public Triangle_common
{
public:
    Triangle_acAC(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_a, corner_A, corner_B, corner_A)
    {
        sides_count = 3;
        name = "Равнобедренный треугольник";
    }

    bool check() override {
        if (!Triangle_common::check() || (side_a == side_b) || (corner_A == corner_B)) return false;
        else return true;
    };
};

class Triangle_C606060 : public Triangle_common
{
public:
    Triangle_C606060(unsigned int side_a) : Triangle_common(side_a, side_a, side_a, 60, 60, 60)
    {
        sides_count = 3;
        name = "Равносторонний треугольник";
    }
    bool check() override {
        if (!Triangle_common::check()) return false;
        else return true;
    };
};



class Quadrangle_ababABAB : public Quadrangle_common
{
public:
    Quadrangle_ababABAB(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Quadrangle_common(side_a, side_b, side_a, side_b, corner_A, corner_B, corner_A, corner_B)
    {
        sides_count = 4;
        name = "Параллелограмм";
    }
    bool check() /*override*/ {
        if (!Quadrangle_common::check() || (side_a == side_b) || (corner_A == corner_B)) return false;
        else return true;
    };
};

class Quadrangle_abab90 : public Quadrangle_ababABAB
{
public:
    Quadrangle_abab90(unsigned int side_a, unsigned int side_b) : Quadrangle_ababABAB(side_a, side_b, 90, 90)
    {
        sides_count = 4;
        name = "Прямоугольник";
    }

    bool check() /*override*/ {
        if (!Quadrangle_common::check() || (side_a == side_b)) return false;
        else return true;
    };
};

class Quadrangle_aABAB : public Quadrangle_ababABAB
{
public:
    Quadrangle_aABAB(unsigned int side_a, unsigned int corner_A, unsigned int corner_B) : Quadrangle_ababABAB(side_a, side_a, corner_A, corner_B)
    {
        sides_count = 4;
        name = "Ромб";
    }

    bool check() /*override*/ {
        if (!Quadrangle_common::check() || (corner_A == corner_B)) return false;
        else return true;
    };
};

class Quadrangle_a90 : public Quadrangle_aABAB
{
public:
    Quadrangle_a90(unsigned int side_a) : Quadrangle_aABAB(side_a, 90, 90)
    {
        sides_count = 4;
        name = "Квадрат";
    }

    bool check() /*override*/ {
        if (!Quadrangle_common::check()) return false;
        else return true;
    };
};

void print_info(Figure* figure) {
    figure->print_info();
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Создается обычный треугольник    
    Triangle_common fig2(10, 20, 30, 50, 60, 70);
    Figure* p_fig2 = &fig2;
    print_info(p_fig2);

    //Создается прямоугольный треугольник   
    Triangle_C90 fig3(10, 20, 30, 50, 40);
    Figure* p_fig3 = &fig3;
    print_info(p_fig3);

    //Создается равнобедренный треугольник   
    Triangle_acAC fig4(10, 20, 50, 60);
    Figure* p_fig4 = &fig4;
    print_info(p_fig4);

    // Создается равносторонний треугольник
    Triangle_C606060 fig5(30);
    Figure* p_fig5 = &fig5;
    print_info(p_fig5);

    //Создается обычный четырехугольник    
    Quadrangle_common fig6(10, 20, 30, 40, 150, 60, 70, 80);
    Figure* p_fig6 = &fig6;
    print_info(p_fig6);

    //Создается параллелограмм
    Quadrangle_ababABAB fig7(20, 30, 30, 40);
    Figure* p_fig7 = &fig7;
    print_info(p_fig7);

    //Создается прямоугольник
    Quadrangle_abab90 fig8(10, 20);
    Figure* p_fig8 = &fig8;
    print_info(p_fig8);

    //Создается ромб
    Quadrangle_aABAB fig9(30, 30, 40);
    Figure* p_fig9 = &fig9;
    print_info(p_fig9);

    //Создается квадрат
    Quadrangle_a90 fig10(20);
    Figure* p_fig10 = &fig10;
    print_info(p_fig10);


    return 0;
}

