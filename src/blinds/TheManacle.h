#pragma once

#include "../Blind.h"

class TheManacle : public Blind
{
public:
    TheManacle() : Blind(2.0, "The Manacle") {}
    ~TheManacle() override = default;
};