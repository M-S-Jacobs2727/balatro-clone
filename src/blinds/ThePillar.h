#pragma once

#include "../Blind.h"

class ThePillar : public Blind
{
public:
    ThePillar() : Blind(2.0, "The Pillar") {}
    ~ThePillar() override = default;
};