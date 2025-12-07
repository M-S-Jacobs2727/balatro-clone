#pragma once

#include "../Blind.h"

class AmberAcorn : public Blind
{
public:
    AmberAcorn() : Blind(2.0, "Amber Acorn") {}
    ~AmberAcorn() override = default;
};