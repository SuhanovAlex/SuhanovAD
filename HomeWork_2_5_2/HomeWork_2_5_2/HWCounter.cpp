#include "HWCounter.h"




int Counter::get_number() {
    return number;
};

void Counter::set_number_increment() {
    ++number;
};

void Counter::set_number_decrement() {
    --number;
};

Counter::Counter(int startNumber, std::string userChoice) : number(1)
{
    if (userChoice == "да") number = startNumber;

};

