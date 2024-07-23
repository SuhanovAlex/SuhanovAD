#include <iostream>
#include <Windows.h>
#define MODE 1

#ifndef MODE
#error Необходимо определить MODE.
#endif

#if MODE == 1
double add(double a, double b) {
    return a + b;
};
#endif

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

#if MODE == 0
    std::cout << "Работаю в режиме тренировки\n";

#elif MODE == 1
    std::cout << "Работаю в боевом режиме\n" << "Введите число 1:\t";
    double a{ 0 };
    std::cin >> a;
    std::cout << "Введите число 2:\t";
    double b{ 0 };
    std::cin >> b;
    std::cout << "Результат сложения:\t" << add(a, b);
#else
    std::cout << "Неизвестный режим. Завершение работы\n";
#endif

    return 0;
}

