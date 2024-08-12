#include "Figure.h"

    unsigned int Figure::get_sides_count() {
        return sides_count;
    };

    std::string Figure::get_name() {
        return name;
    };

    /*virtual*/ void Figure::print_info() {
        std::cout << get_name() << " (сторон -  " << get_sides_count() << "):" << std::endl;
    };

    bool Figure::check() {
        if (sides_count != 0) return true;
        else return false;
    }

    Figure::Figure() {
        sides_count = 0;
        name = "Фигура";
    };

    Figure::Figure(unsigned int sides_count, std::string name) {
        this->sides_count = sides_count;
        this->name = name;
    };


