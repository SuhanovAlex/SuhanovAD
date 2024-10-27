#include <iostream>
#include <stdexcept> // Для исключений

class smart_array {
private:
    int* array;       // Указатель на массив
    int size;         // Ёмкость массива
    int count;        // Текущее количество элементов

public:
    // Конструктор
    smart_array(int initial_size) : size(initial_size), count(0) {
        if (size <= 0) {
            throw std::invalid_argument("Size must be greater than 0."); // Исключение при ошибке
        }
        array = new int[size]; // Выделение памяти
    }

    // Деструктор
    ~smart_array() {
        delete[] array; // Очистка памяти
    }

    // Функция добавления нового элемента
    void add_element(int element) {
        if (count >= size) {
            throw std::overflow_error("Array limit reached."); // Исключение при переполнении
        }
        array[count++] = element; // Добавление элемента
    }

    // Функция получения элемента по индексу
    int get_element(int index) const {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of range."); // Исключение при некорректном индексе
        }
        return array[index]; // Возврат элемента
    }
};

// Пример использования
int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl; // Вывод: 4
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl; // Вывод сообщения об ошибке
    }
    return 0;
}
