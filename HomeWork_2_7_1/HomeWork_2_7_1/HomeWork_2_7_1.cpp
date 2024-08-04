#include <iostream>
#include <Windows.h>
#include <string>

int LengthCheck(int forbidden_length) {
    if (forbidden_length <= 0) throw "Количество символов должно быть натуральным числом!";
    return forbidden_length;
}

int function(std::string str, int forbidden_length)
{
    if (str.length() == forbidden_length) throw "Вы ввели слово запретной длины! До свидания\n";
    return str.length();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Введите запретную длину:  ";
    int forbidden_length{ -99 };
    std::cin >> forbidden_length;
    try 
    {
        LengthCheck(forbidden_length);
    }
    catch (const char* error_message)
    {
        std::cout << error_message << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cout << "Неизвестная ошибка!" << std::endl;
        return 0;
    }
    std::string str;
    do
    {
        std::cout << "Введите слово: ";
        std::cin >> str;
        try
        {
            function(str, forbidden_length);
        }
        catch (const char* bad_length)
        {
            std::cout << bad_length << std::endl;
            return 0;
        }
        catch (...)
        {
            std::cout << "Неизвестная ошибка!" << std::endl;
            return 0;
        }
        std::cout << "Длина слова равна " << str.length() << std::endl;
    } while (function(str, forbidden_length) != forbidden_length);

    return 0;
}

