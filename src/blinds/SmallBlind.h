#pragma once

#include "../Blind.h"

class SmallBlind : public Blind
{
public:
    SmallBlind() : Blind(1.0, "Small Blind") {}
    ~SmallBlind() override = default;
};