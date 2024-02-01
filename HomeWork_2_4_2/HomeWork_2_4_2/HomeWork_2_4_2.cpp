

#include <iostream>
#include <Windows.h>

class Figure
{
protected:
    unsigned int sides_count;
    std::string name;

public:
    unsigned int get_sides_count() {
        return sides_count;
    };

    std::string get_name() {
        return name;
    };

    Figure() {
        sides_count = 0;
        name = "Фигура";
    };

    Figure(unsigned int sides_count, std::string name) {
        this->sides_count = sides_count;
        this->name = name;
    };


};

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
    unsigned int get_side_a() {
        return side_a;
    };
    unsigned int get_side_b() {
        return side_b;
    };
    unsigned int get_side_c() {
        return side_c;
    };
    unsigned int get_corner_A() {
        return corner_A;
    };
    unsigned int get_corner_B() {
        return corner_B;
    };
    unsigned int get_corner_C() {
        return corner_C;
    };
    Triangle_common() : Figure(3, "Треугольник")
    {};
    Triangle_common(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B, unsigned int corner_C) : Figure(3, "Треугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        this->corner_C = corner_C;
    }
};

class Triangle_C90 : public Figure, public Triangle_common
{
public:
    Triangle_C90(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B) : Figure(3, "Прямоугольный треугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        corner_C = 90;
    }
};

class Triangle_acAC : public Figure, public Triangle_common
{
public:
    Triangle_acAC(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Figure(3, "Равнобедренный треугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_a;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        this->corner_C = corner_A;
    }
};

class Triangle_C606060 : public Figure, public Triangle_common
{
public:
    Triangle_C606060(unsigned int side_a) : Figure(3, "Равносторонний треугольник")
    {
        this->side_a = side_a;
        this->side_b = side_a;
        this->side_c = side_a;
        corner_A = 60;
        corner_B = 60;
        corner_C = 60;
    }
};

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
    unsigned int get_side_a() {
        return side_a;
    };
    unsigned int get_side_b() {
        return side_b;
    };
    unsigned int get_side_c() {
        return side_c;
    };
    unsigned int get_side_d() {
        return side_d;
    };
    unsigned int get_corner_A() {
        return corner_A;
    };
    unsigned int get_corner_B() {
        return corner_B;
    };
    unsigned int get_corner_C() {
        return corner_C;
    };
    unsigned int get_corner_D() {
        return corner_D;
    };
    Quadrangle_common() : Figure(4, "Четырехугольник")
    {}
    Quadrangle_common(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int side_d, unsigned int corner_A, unsigned int corner_B, unsigned int corner_C, unsigned int corner_D) : Figure(4, "Четырехугольник")
    {
        this->side_a = side_a;
        this->side_b = side_b;
        this->side_c = side_c;
        this->side_d = side_d;
        this->corner_A = corner_A;
        this->corner_B = corner_B;
        this->corner_C = corner_C;
        this->corner_D = corner_D;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Создается обычный треугольник    
    Triangle_common fig2(10,20,30,50,60,70);
    std::cout << fig2.Figure::get_name() << " (сторон -  " << fig2.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << fig2.get_side_a() << " b=" << fig2.get_side_b() << " c=" << fig2.get_side_c() << std::endl;
    std::cout << "Углы: A=" << fig2.get_corner_A() << " B=" << fig2.get_corner_B() << " C=" << fig2.get_corner_C() << std::endl << std::endl;
    
    //Создается прямоугольный треугольник   
    Triangle_C90 fig3(10,20,30,50,60);
    std::cout << fig3.Figure::get_name() << " (сторон -  " << fig3.Figure:: get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << fig3.get_side_a() << " b=" << fig3.get_side_b() << " c=" << fig3.get_side_c() << std::endl;
    std::cout << "Углы: A=" << fig3.get_corner_A() << " B=" << fig3.get_corner_B() << " C=" << fig3.get_corner_C() << std::endl << std::endl;
    
    //Создается равнобедренный треугольник   
    Triangle_acAC fig4(10, 20, 50, 60);
    std::cout << fig4.Figure::get_name() << " (сторон -  " << fig4.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << fig4.get_side_a() << " b=" << fig4.get_side_b() << " c=" << fig4.get_side_c() << std::endl;
    std::cout << "Углы: A=" << fig4.get_corner_A() << " B=" << fig4.get_corner_B() << " C=" << fig4.get_corner_C() << std::endl << std::endl;

    // Создается равносторонний треугольник
    Triangle_C606060 fig5(30);
    std::cout << fig5.Figure::get_name() << " (сторон -  " << fig5.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << fig5.get_side_a() << " b=" << fig5.get_side_b() << " c=" << fig5.get_side_c() << std::endl;
    std::cout << "Углы: A=" << fig5.get_corner_A() << " B=" << fig5.get_corner_B() << " C=" << fig5.get_corner_C() << std::endl << std::endl;

    //Создается обычный четырехугольник    
    Quadrangle_common fig6(10, 20, 30, 40, 50, 60, 70, 80);
    std::cout << fig6.Figure::get_name() << " (сторон -  " << fig6.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << fig6.get_side_a() << " b=" << fig6.get_side_b() << " c=" << fig6.get_side_c() << " d=" << fig6.get_side_d() << std::endl;
    std::cout << "Углы: A=" << fig6.get_corner_A() << " B=" << fig6.get_corner_B() << " C=" << fig6.get_corner_C() << " D=" << fig6.get_corner_D() << std::endl << std::endl;


    
    
    
    return 0;
}

