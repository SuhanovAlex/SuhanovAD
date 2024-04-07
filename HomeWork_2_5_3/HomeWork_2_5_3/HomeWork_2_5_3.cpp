

#include "Figure.h"
#include "Triangle_common.h"
#include "Triangle_C90.h"
#include "Triangle_acAC.h"
#include "Triangle_C606060.h"
#include "Quadrangle_common.h"
#include "Quadrangle_ababABAB.h"
#include "Quadrangle_abab90.h"
#include "Quadrangle_aABAB.h"
#include "Quadrangle_a90.h"
#include <Windows.h>

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

