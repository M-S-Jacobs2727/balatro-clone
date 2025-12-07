#pragma once

#include "../Blind.h"

class TheNeedle : public Blind
{
public:
    TheNeedle() : Blind(1.0, "The Needle") {}
    ~TheNeedle() override = default;
};