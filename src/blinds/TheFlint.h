#pragma once

#include "../Blind.h"

class TheFlint : public Blind
{
public:
    TheFlint() : Blind(2.0, "The Flint") {}
    ~TheFlint() override = default;
};