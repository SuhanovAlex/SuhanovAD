#include <iostream>
#include <Windows.h>

const int MAX_N = 50; 

int fib(int n, unsigned long memo[]) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n{ -999 };

    do {
        std::cout << "Введите порядковый номер числа Фибоначчи (натуральное число) не больше " << MAX_N << ": ";
        std::cin >> n;
    } while (n <= 0 || n > MAX_N);

        unsigned long memo[MAX_N]; 
        memo[0] = 0;
        memo[1] = 1;
        if (n > 2) {
            for (int i = 2; i < n; i++) {
                memo[i] = -1;
            };
        };
        
        
        std::cout << "Число Фибоначчи с порядковым номером " << n << ": " << fib(n-1, memo) << std::endl;
        
    

    return 0;
}
