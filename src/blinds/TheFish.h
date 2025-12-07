#pragma once

#include "../Blind.h"

class TheFish : public Blind
{
public:
    TheFish() : Blind(2.0, "The Fish") {}
    ~TheFish() override = default;
};