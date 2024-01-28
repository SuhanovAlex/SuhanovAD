

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    std::string get_city() {
        return city;
    };

    std::string get_street() {
        return street;
    };

    int get_house() {
        return house;
    };

    int get_apartment() {
        return apartment;
    };

    Address()
    {
        city = "undefined";
        street = "undefined";
        house = -10;
        apartment = -10;
    };
    Address(std::string city, std::string street, int house, int apartment)
    {
        this->city = city;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::ifstream fin;
    fin.open("in.txt");
    std::string rows{ "" };
    fin >> rows;
    int ROWS = std::stoi(rows);
    std::string tmp_city{ "XYZ" };
    std::string tmp_street{ "ZYX" };
    int tmp_house{ -1 };
    int tmp_apartment{ -1 };

    std::ofstream fout;
    fout.open("out.txt");
    fout << ROWS << std::endl;
    Address* mas = new Address[ROWS]();
    for (int i = 0; i < ROWS; ++i) {
        fin >> tmp_city;
        fin >> tmp_street;
        fin >> tmp_house;
        fin >> tmp_apartment;
        mas[i] = Address(tmp_city, tmp_street, tmp_house, tmp_apartment);
    };
    for (int i = ROWS - 1; i >= 0; --i) {
        fout << mas[i].get_city() << ", " << mas[i].get_street() << ", " << mas[i].get_house() << ", " << mas[i].get_apartment() << std::endl;
    }
    fin.close();
    fout.close();
    delete[] mas;
    return 0;
}



