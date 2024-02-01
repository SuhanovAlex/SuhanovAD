

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
        this -> sides_count = sides_count;
        this -> name = name;
    };


};

class Triangle : public Figure
{
public:
    Triangle() : Figure (3,"Треугольник")
    {}
};

class Quadrangle : public Figure
{
public:
    Quadrangle() : Figure(4, "Четырехугольник")
    {}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Количество сторон:" << std::endl;
    Figure fig1;
    std::cout << fig1.get_name() << ": " << fig1.get_sides_count() << std::endl;
    Triangle fig2;
    std::cout << fig2.get_name() << ": " << fig2.get_sides_count() << std::endl;
    Quadrangle fig3;
    std::cout << fig3.get_name() << ": " << fig3.get_sides_count() << std::endl;
    return 0;
}

