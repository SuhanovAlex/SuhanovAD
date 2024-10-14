#include <iostream>
#include <string>
#include <Windows.h>

void print_element(int level, const std::string& childType, int value, int parentValue) {
    if (childType == "root") {
        std::cout << level << " " << childType << " " << value << std::endl;
    }
    else {
        std::cout << level << " " << childType << "(" << parentValue << ") " << value << std::endl;
    }
}

void print_pyramid(int* array, int size) {
    if (size == 0) return; 

    
    print_element(0, "root", array[0], 0);

    
    for (int i = 1; i < size; ++i) {
        int level = 0;
        int index = i;

        
        while (index > 0) {
            index = (index - 1) / 2;
            level++;
        }

        
        std::string childType = (i % 2 == 1) ? "left" : "right";
        int parentIndex = (i - 1) / 2; 

        
        print_element(level, childType, array[i], array[parentIndex]);
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void print_current_position(int index, int* array, int size) {
    int level = 0;
    int currentIndex = index;

    
    while (currentIndex > 0) {
        currentIndex = (currentIndex - 1) / 2;
        level++;
    }

    if (index == 0) {
        print_element(0, "root", array[index], 0);
    }
    else {
        int parentIndex = (index - 1) / 2;
        std::string childType = (index % 2 == 1) ? "left" : "right";
        print_element(level, childType, array[index], array[parentIndex]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int array[] = { 1, 3, 6, 5, 9, 8 };
    int size = sizeof(array) / sizeof(array[0]);

    std::cout << "Исходный массив: ";
    print_array(array, size);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(array, size);

    int currentIndex = 0; 
    std::string command;

    do {
        
        std::cout << "Вы находитесь здесь: ";
        print_current_position(currentIndex, array, size);

        
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == "up") {
            if (currentIndex == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }
            else {
                currentIndex = (currentIndex - 1) / 2; 
                std::cout << "Ок" << std::endl;
            }
        }
        else if (command == "left") {
            int leftChildIndex = 2 * currentIndex + 1; 
            if (leftChildIndex < size) {
                currentIndex = leftChildIndex;
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
            }
        }
        else if (command == "right") {
            int rightChildIndex = 2 * currentIndex + 2; 
            if (rightChildIndex < size) {
                currentIndex = rightChildIndex;
                std::cout << "Ок" << std::endl;
            }
            else {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
            }
        }

    } while (command != "exit");

    return 0;
}
