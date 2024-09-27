#include <iostream>
#include <Windows.h>

void quick_sort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right]; 
        int i = left - 1;       

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]); 
            }
        }
        std::swap(arr[i + 1], arr[right]); 
        int pi = i + 1; 

        
        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}




int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    quick_sort(arr1, 0, size1 - 1);
    std::cout << "Отсортированный массив 1: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "Исходный массив 2: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    quick_sort(arr2, 0, size2 - 1);
    std::cout << "Отсортированный массив 2: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "Исходный массив 3: ";
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    quick_sort(arr3, 0, size3 - 1);
    std::cout << "Отсортированный массив 3: ";
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}
