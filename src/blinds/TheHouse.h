#pragma once

#include "../Blind.h"

class TheHouse : public Blind
{
public:
    TheHouse() : Blind(2.0, "The House") {}
    ~TheHouse() override = default;
};