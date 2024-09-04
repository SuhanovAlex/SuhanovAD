

#include <iostream>
#include <Windows.h>

int CountNums(int* arr, int num) {
    int left = 0;
    int right = sizeof(arr);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > num) 
            right = mid; 
        
        else 
            left = mid + 1; 
        return sizeof(arr) - left;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Введите точку отсчёта : ";
    int Num;
    std::cin >> Num;
    int matr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    std::cout << "Количество элементов в массиве больших, чем " << Num << ":" << CountNums(matr, Num);
    return 0;
}

