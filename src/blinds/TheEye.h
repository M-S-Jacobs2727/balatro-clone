#pragma once

#include "../Blind.h"

class TheEye : public Blind
{
public:
    TheEye() : Blind(2.0, "The Eye") {}
    ~TheEye() override = default;
};