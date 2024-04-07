#pragma once
#include "Triangle_common.h"

class Triangle_acAC : public Triangle_common
{
public:
    Triangle_acAC(unsigned int, unsigned int, unsigned int, unsigned int);
    bool check() override;
};