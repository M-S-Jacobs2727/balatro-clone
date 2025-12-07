#pragma once

#include "../Blind.h"

class TheOx : public Blind
{
public:
    TheOx() : Blind(2.0, "The Ox") {}
    ~TheOx() override = default;
};