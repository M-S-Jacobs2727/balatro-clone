#pragma once

#include "../Blind.h"

class CrimsonHeart : public Blind
{
public:
    CrimsonHeart() : Blind(2.0, "Crimson Heart") {}
    ~CrimsonHeart() override = default;
};