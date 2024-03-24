#pragma once
#include <iostream>

class Counter {
private:
    int number;

public:
    int get_number();
    void set_number_increment();
    void set_number_decrement();
    Counter(int, std::string);
};