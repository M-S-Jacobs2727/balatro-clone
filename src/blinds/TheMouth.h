#pragma once

#include "../Blind.h"

class TheMouth : public Blind
{
public:
    TheMouth() : Blind(2.0, "The Mouth") {}
    ~TheMouth() override = default;
};