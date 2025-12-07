#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Glass : public Enhancement
{
public:
    Glass() : Enhancement("Glass") {}
    ~Glass() = default;

    void on_count(GameData& data)
    {
        data.mult_score *= 2.0;
        // TODO: Add a queue system to handle the effects of the glass after count
    }
};