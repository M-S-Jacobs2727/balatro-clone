#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Gold : public Enhancement
{
public:
    Gold() : Enhancement("Gold") {}
    ~Gold() = default;

    void on_round_end(GameData& data) { data.money += 3; }
};