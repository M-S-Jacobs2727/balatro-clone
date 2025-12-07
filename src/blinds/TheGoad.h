#pragma once

#include "../Blind.h"

class TheGoad : public Blind
{
public:
    TheGoad() : Blind(2.0, "The Goad") {}
    ~TheGoad() override = default;
};