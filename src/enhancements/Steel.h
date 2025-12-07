#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Steel : public Enhancement
{
public:
    Steel() : Enhancement("Steel") {}
    ~Steel() = default;

    void on_in_hand_trigger(GameData& data) { data.mult_score *= 1.5; }
};