#pragma once

#include "../Blind.h"

class TheArm : public Blind
{
public:
    TheArm() : Blind(2.0, "The Arm") {}
    ~TheArm() override = default;
};