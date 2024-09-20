#include <iostream>
#include <Windows.h>




int fib(int n) {
    
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }

    
    return fib(n - 1) + fib(n - 2);
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    std::cout << "Введите порядковый номер числа Фибоначчи (натуральное число): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Пожалуйста, введите натуральное число (порядковый номер)." << std::endl;
    }
    else {
        std::cout << "Число Фибоначчи " << n << ": " << fib(n) << std::endl;
    }

    return 0;
}
