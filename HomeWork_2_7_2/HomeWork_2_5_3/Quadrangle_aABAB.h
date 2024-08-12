#pragma once
#include "Quadrangle_ababABAB.h"

class Quadrangle_aABAB : public Quadrangle_ababABAB
{
public:
    Quadrangle_aABAB(unsigned int, unsigned int, unsigned int);

    bool check() override;
};
