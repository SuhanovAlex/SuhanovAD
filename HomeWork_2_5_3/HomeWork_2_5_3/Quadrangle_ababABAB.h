#pragma once
#include "Quadrangle_common.h"

class Quadrangle_ababABAB : public Quadrangle_common
{
public:
    Quadrangle_ababABAB(unsigned int, unsigned int, unsigned int, unsigned int);
    bool check() override;
};
