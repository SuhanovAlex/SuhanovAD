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

    // Конструктор копирования
    smart_array(const smart_array& other): size(other.size), count(other.count) {
        array = new int[size]; // Выделение новой памяти
        for (int i = 0; i < count; ++i) {
            array[i] = other.array[i]; // Копирование элементов
        }
    }

    // Оператор присваивания
    smart_array& operator=(const smart_array& other) {
        if (this != &other) { // Проверка на самоприсваивание
            delete[] array; // Освобождение предыдущего массива
            size = other.size;
            count = other.count;
            array = new int[size]; // Выделение новой памяти
            for (int i = 0; i < count; ++i) {
                array[i] = other.array[i]; // Копирование элементов
            }
        }
        return *this;
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


int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array; // Присваивание нового массива
        std::cout << arr.get_element(1) << std::endl; // Вывод: 34
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl; // Вывод сообщения об ошибке
    }
    return 0;
}
