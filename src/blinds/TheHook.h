#pragma once

#include "../Blind.h"

class TheHook : public Blind
{
public:
    TheHook() : Blind(2.0, "The Hook") {}
    ~TheHook() override = default;
};