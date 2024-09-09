#include <iostream>
#include <Windows.h>

int CountNums(int* arr, int size, int num) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > num)
            right = mid;
        else
            left = mid + 1;
    }

    // Количество элементов, больших чем num
    return size - left;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::cout << "Введите точку отсчёта: ";
    int Num;
    std::cin >> Num;

    int matr[9] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(matr) / sizeof(matr[0]); // Определяем размер массива

    std::cout << "Количество элементов в массиве больших, чем " << Num << ": " << CountNums(matr, size, Num);

    return 0;
}