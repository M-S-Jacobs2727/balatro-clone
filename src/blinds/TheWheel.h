#pragma once

#include "../Blind.h"

class TheWheel : public Blind
{
public:
    TheWheel() : Blind(2.0, "The Wheel") {}
    ~TheWheel() override = default;
};