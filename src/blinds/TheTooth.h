#pragma once

#include "../Blind.h"

class TheTooth : public Blind
{
public:
    TheTooth() : Blind(2.0, "The Tooth") {}
    ~TheTooth() override = default;
};