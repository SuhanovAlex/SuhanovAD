#pragma once
#include "Quadrangle_ababABAB.h"

class Quadrangle_abab90 : public Quadrangle_ababABAB
{
public:
    Quadrangle_abab90(unsigned int, unsigned int);
    bool check() override;
};
