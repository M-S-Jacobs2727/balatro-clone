#pragma once

#include "../Blind.h"

class TheSerpent : public Blind
{
public:
    TheSerpent() : Blind(2.0, "The Serpent") {}
    ~TheSerpent() override = default;
};