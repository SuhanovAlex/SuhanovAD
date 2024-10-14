#include <iostream>
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
        int parentIndex = (i - 1) / 2; 

        
        int powerOfTwo = 1; 
        while (powerOfTwo - 1 < i + 1) {
            level++;
            powerOfTwo *= 2; 
        }

        
        std::string childType = (i % 2 == 1) ? "left" : "right";

        
        print_element(level - 1, childType, array[i], array[parentIndex]);
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int actual_size, logical_size;
    
    int array1[] = { 1, 3, 6, 5, 9, 8 };
    int size1 = sizeof(array1) / sizeof(array1[0]);

    std::cout << "Исходный массив: ";
    print_array(array1, size1);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(array1, size1);

    std::cout << std::endl;

    int array2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int size2 = sizeof(array2) / sizeof(array2[0]);

    std::cout << "Исходный массив: ";
    print_array(array2, size2);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(array2, size2);

    std::cout << std::endl;

    int array3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size3 = sizeof(array3) / sizeof(array3[0]);

    std::cout << "Исходный массив: ";
    print_array(array3, size3);
    std::cout << "Пирамида:" << std::endl;
    print_pyramid(array3, size3);

    return 0;
}
