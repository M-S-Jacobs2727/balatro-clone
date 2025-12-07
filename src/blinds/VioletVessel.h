#pragma once

#include "../Blind.h"

class VioletVessel : public Blind
{
public:
    VioletVessel() : Blind(6.0, "Violet Vessel") {}
    ~VioletVessel() override = default;
};