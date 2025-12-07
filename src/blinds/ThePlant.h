#pragma once

#include "../Blind.h"

class ThePlant : public Blind
{
public:
    ThePlant() : Blind(2.0, "The Plant") {}
    ~ThePlant() override = default;
};