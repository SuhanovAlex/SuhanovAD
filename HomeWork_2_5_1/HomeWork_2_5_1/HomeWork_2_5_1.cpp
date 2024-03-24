// HomeWork_2_5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "HWMath.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Введите первое число:\t";
    int num1{-1};
    std::cin >> num1;
    std::cout << "Введите второе число:\t";
    int num2{-1};
    std::cin >> num2;
    std::cout << "Первое число:\t" << num1 << std::endl;
    std::cout << "Второе число:\t" << num2 << std::endl;
    int user_choice{ -1 };
    while (user_choice != 0) {
        std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 0 - выход из программы):\t";
        std::cin >> user_choice;
        switch (user_choice) {
            case 1:
                std::cout << num1 << " плюс " << num2 << " = " << addition(num1, num2) << std::endl; break;
            case 2:
                std::cout << num1 << " минус " << num2 << " = " << subtraction(num1, num2) << std::endl; break;
            case 3:
                std::cout << num1 << " умножить на " << num2 << " = " << multiplication(num1, num2) << std::endl; break;
            case 4:
                std::cout << num1 << " разделить на " << num2 << " = " << division(num1, num2) << std::endl; break;
            case 5:
                std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << std::endl; break;
            case 0:
                std::cout << "До свидания." << std::endl; break;
            default:
                std::cout << "Неверный ввод." << std::endl; break;
        };
    };
    return 0;

}