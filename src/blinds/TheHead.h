#pragma once

#include "../Blind.h"

class TheHead : public Blind
{
public:
    TheHead() : Blind(2.0, "The Head") {}
    ~TheHead() override = default;
};