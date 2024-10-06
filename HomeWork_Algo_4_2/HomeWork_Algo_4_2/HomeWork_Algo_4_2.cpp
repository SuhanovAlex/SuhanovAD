#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        }
        else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

void append_to_dynamic_array(int*& arr, int& logical_size, int& actual_size, int new_element) {
    if (logical_size < actual_size) {
        arr[logical_size] = new_element;
        ++logical_size;
    }
    else {
        int new_size = actual_size + 3;
        int* new_arr = new int[new_size];
        for (int i = 0; i < logical_size; ++i) {
            new_arr[i] = arr[i];
        }
        new_arr[logical_size] = new_element;
        ++logical_size;
        delete[] arr;
        arr = new_arr;
        actual_size = new_size;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int actual_size, logical_size;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;

    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    int new_element;
    std::cout << "Введите элемент для добавления (0 для завершения): ";
    std::cin >> new_element;

    while (new_element != 0) {
        append_to_dynamic_array(arr, logical_size, actual_size, new_element);
        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);

        std::cout << "Введите элемент для добавления (0 для завершения): ";
        std::cin >> new_element;
    }

    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return 0;
}
