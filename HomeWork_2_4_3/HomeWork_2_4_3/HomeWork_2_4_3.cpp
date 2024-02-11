

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

    virtual void print_info() {
        std::cout << get_name() << " (сторон -  " << get_sides_count() << "):" << std::endl;
    };

    bool check() {
        if (sides_count != 0) return true;
        else return false;
    }

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
    virtual bool check() {
        if ((side_a == 0) || (side_b == 0) || (side_c == 0) || (corner_A + corner_B + corner_C) != 180) return false;
        else return true;
    };
    void print_info() override {
        Figure::print_info();
        if (check()) std::cout << "Правильная." << std::endl;
        else std::cout << "Неправильная." << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_corner_A() << " B=" << get_corner_B() << " C=" << get_corner_C() << std::endl << std::endl;
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

    virtual bool check() {
        if ((side_a == 0) || (side_b == 0) || (side_c == 0) || (side_d == 0) || (corner_A + corner_B + corner_C + corner_D) != 360) return false;
        else return true;
    };

    void print_info() override {
        Figure::print_info();
        if (check()) std::cout << "Правильная." << std::endl;
        else std::cout << "Неправильная." << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_corner_A() << " B=" << get_corner_B() << " C=" << get_corner_C() << " D=" << get_corner_D() << std::endl << std::endl;

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
    bool check() override {
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

    bool check() override {
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

    bool check() override {
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

    bool check() override {
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

