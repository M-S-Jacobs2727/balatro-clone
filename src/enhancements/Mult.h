#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Mult : public Enhancement
{
public:
    Mult() : Enhancement("Mult") {}
    ~Mult() = default;

    void on_count(GameData& data) { data.mult_score += 4; }
};