#include <iostream>
#include <Windows.h>

class Counter {
private:
    int number;

public:
    int get_number() {
        return number;
    };

    void set_number_increment() {
        ++number;
    };

    void set_number_decrement() {
        --number;
    };

    Counter(int startNumber, std::string userChoice): number(1)
    {
        if (userChoice == "��") number = startNumber;
        
    };

};

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "�������� �������� �� ��������� - 1 (����). �� ������ �������� ��������� �������� ��������? ������� '��' ��� '���':";
    std::string userChoice;
    std::cin >> userChoice;
    while (userChoice != "��" && userChoice != "���") {
        std::cout << "�������� ����. ������� '��' ��� '���':";
        std::cin >> userChoice;
    };
    
    int startNumber {99999};
    if (userChoice == "��") {
        std::cout << "������� ��������� �������� �������� (������ ���� ����� �����):";        
        std::cin >> startNumber;
    }
    Counter count1(startNumber, userChoice);
    while (userChoice != "x") {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> userChoice;
        if (userChoice == "+") {
            count1.set_number_increment();
        }
        else if (userChoice == "-") {
            count1.set_number_decrement();
        }
        else if (userChoice == "=") {
            std::cout << count1.get_number() << std::endl;
        }
        else if (userChoice == "x") {
            std::cout << "�� ��������!";
        }
        else {
            std::cout << "�������� ����!" << std::endl;
        }
    }
    return 0;
}