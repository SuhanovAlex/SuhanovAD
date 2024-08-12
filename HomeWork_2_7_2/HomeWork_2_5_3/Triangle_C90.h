#pragma once
#include "Triangle_common.h"

class Triangle_C90 : public Triangle_common
{
public:
    Triangle_C90(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    bool check() override;
};