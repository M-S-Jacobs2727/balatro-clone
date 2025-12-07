#pragma once

#include "../Blind.h"

class TheWater : public Blind
{
public:
    TheWater() : Blind(2.0, "The Water") {}
    ~TheWater() override = default;
};