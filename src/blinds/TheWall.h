#pragma once

#include "../Blind.h"

class TheWall : public Blind
{
public:
    TheWall() : Blind(4.0, "The Wall") {}
    ~TheWall() override = default;
};