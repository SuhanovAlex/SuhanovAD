

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

class Triangle_C90 : public Triangle_common
{
public:
    Triangle_C90(unsigned int side_a, unsigned int side_b, unsigned int side_c, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_c, corner_A, corner_B, 90)
    {
        sides_count = 3;
        name = "Прямоугольный треугольник";
    }
};

class Triangle_acAC : public Triangle_common
{
public:
    Triangle_acAC(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Triangle_common(side_a, side_b, side_a, corner_A, corner_B, corner_A)
    {
        sides_count = 3;
        name = "Равнобедренный треугольник";
    }
};

class Triangle_C606060 : public Triangle_common
{
public:
    Triangle_C606060(unsigned int side_a) : Triangle_common(side_a,side_a,side_a,60,60,60)
    {
        sides_count = 3;
        name = "Равносторонний треугольник";
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

class Quadrangle_ababABAB : public Quadrangle_common
{
public:
    Quadrangle_ababABAB(unsigned int side_a, unsigned int side_b, unsigned int corner_A, unsigned int corner_B) : Quadrangle_common(side_a, side_b, side_a, side_b, corner_A, corner_B, corner_A, corner_B)
    {
        sides_count = 4;
        name = "Параллелограмм";
    }
};

class Quadrangle_abab90 : public Quadrangle_ababABAB
{
public:
    Quadrangle_abab90(unsigned int side_a, unsigned int side_b) : Quadrangle_ababABAB (side_a, side_b, 90,90)
    {
        sides_count = 4;
        name = "Прямоугольник";
    }
};

class Quadrangle_aABAB : public Quadrangle_ababABAB
{
public:
    Quadrangle_aABAB(unsigned int side_a, unsigned int corner_A, unsigned int corner_B) : Quadrangle_ababABAB(side_a, side_a, corner_A, corner_B)
    {
        sides_count = 4;
        name = "Ромб";
    }
};

class Quadrangle_a90 : public Quadrangle_aABAB
{
public:
    Quadrangle_a90(unsigned int side_a) : Quadrangle_aABAB(side_a, 90, 90)
    {
        sides_count = 4;
        name = "Квадрат";
    }
};

void print_info_triangle(Triangle_common triangle) {
    std::cout << triangle.Figure::get_name() << " (сторон -  " << triangle.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << triangle.get_side_a() << " b=" << triangle.get_side_b() << " c=" << triangle.get_side_c() << std::endl;
    std::cout << "Углы: A=" << triangle.get_corner_A() << " B=" << triangle.get_corner_B() << " C=" << triangle.get_corner_C() << std::endl << std::endl;
};

void print_info_quadrangle(Quadrangle_common quadrangle) {
    std::cout << quadrangle.Figure::get_name() << " (сторон -  " << quadrangle.Figure::get_sides_count() << "):" << std::endl;
    std::cout << "Стороны: a=" << quadrangle.get_side_a() << " b=" << quadrangle.get_side_b() << " c=" << quadrangle.get_side_c() << " d=" << quadrangle.get_side_d() << std::endl;
    std::cout << "Углы: A=" << quadrangle.get_corner_A() << " B=" << quadrangle.get_corner_B() << " C=" << quadrangle.get_corner_C() << " D=" << quadrangle.get_corner_D() << std::endl << std::endl;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Создается обычный треугольник    
    Triangle_common fig2(10,20,30,50,60,70);
    print_info_triangle(fig2);
    
    //Создается прямоугольный треугольник   
    Triangle_C90 fig3(10,20,30,50,60);
    print_info_triangle(fig3);
     
    //Создается равнобедренный треугольник   
    Triangle_acAC fig4(10, 20, 50, 60);
    print_info_triangle(fig4);
    
    // Создается равносторонний треугольник
    Triangle_C606060 fig5(30);
    print_info_triangle(fig5);
    
    //Создается обычный четырехугольник    
    Quadrangle_common fig6(10, 20, 30, 40, 50, 60, 70, 80);
    print_info_quadrangle(fig6);
    
    //Создается параллелограмм
    Quadrangle_ababABAB fig7(20, 30, 30, 40);
    print_info_quadrangle(fig7);
    
    //Создается прямоугольник
    Quadrangle_abab90 fig8(10, 20);
    print_info_quadrangle(fig8);
    
    //Создается ромб
    Quadrangle_aABAB fig9(30, 30, 40);
    print_info_quadrangle(fig9);
    
    //Создается квадрат
    Quadrangle_a90 fig10(20);
    print_info_quadrangle(fig10);
    
    
    return 0;
}

