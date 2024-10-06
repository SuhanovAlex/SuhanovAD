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

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    if (logical_size - 1 > actual_size / 3) {
        for (int i = 1; i < logical_size; ++i) {
            arr[i - 1] = arr[i];
        }
        --logical_size;
    }
    else {
        int new_size = actual_size / 3;
        if (new_size < 1) new_size = 1;
        int* new_arr = new int[new_size];
        for (int i = 1; i < logical_size; ++i) {
            new_arr[i - 1] = arr[i];
        }
        --logical_size;
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

    std::string answer;
    while (true) {
        std::cout << "Хотите удалить первый элемент (да/нет)? ";
        std::cin >> answer;

        if (answer == "да") {
            if (logical_size <= 0) {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                break;
            }
            remove_dynamic_array_head(arr, logical_size, actual_size);
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else if (answer == "нет") {
            std::cout << "Спасибо! Ваш массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else {
            std::cout << "Неверный ввод. Пожалуйста, введите 'да' или 'нет'." << std::endl;
        }
    }

    delete[] arr;
    return 0;
}
