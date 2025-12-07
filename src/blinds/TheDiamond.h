#pragma once

#include "../Blind.h"

class TheDiamond : public Blind
{
public:
    TheDiamond() : Blind(2.0, "The Diamond") {}
    ~TheDiamond() override = default;
};