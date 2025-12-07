#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Bonus : public Enhancement
{
public:
    Bonus() : Enhancement("Bonus") {}
    ~Bonus() = default;

    void on_count(GameData& data) { data.chip_score += 30; }
};