#pragma once

#include "../Blind.h"

class TheMark : public Blind
{
public:
    TheMark() : Blind(2.0, "The Mark") {}
    ~TheMark() override = default;
};