#pragma once

#include "../Blind.h"

class CeruleanBell : public Blind
{
public:
    CeruleanBell() : Blind(2.0, "Cerulean Bell") {}
    ~CeruleanBell() override = default;
};