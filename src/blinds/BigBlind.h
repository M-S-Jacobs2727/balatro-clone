#pragma once

#include "../Blind.h"

class BigBlind : public Blind
{
public:
    BigBlind() : Blind(1.5, "Big Blind") {}
    ~BigBlind() override = default;
};