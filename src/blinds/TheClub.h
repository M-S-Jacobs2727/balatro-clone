#pragma once

#include "../Blind.h"

class TheClub : public Blind
{
public:
    TheClub() : Blind(2.0, "The Club") {}
    ~TheClub() override = default;
};