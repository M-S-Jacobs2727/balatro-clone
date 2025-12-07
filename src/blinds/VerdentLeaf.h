#pragma once

#include "../Blind.h"

class VerdentLeaf : public Blind
{
public:
    VerdentLeaf() : Blind(2.0, "Verdent Leaf") {}
    ~VerdentLeaf() override = default;
};