#pragma once
#include <iostream>

class Figure
{
protected:
    unsigned int sides_count;
    std::string name;

public:
    unsigned int get_sides_count();

    std::string get_name();

    virtual void print_info();

    bool check();

    Figure();

    Figure(unsigned int, std::string);


};
