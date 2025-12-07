#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Lucky : public Enhancement
{
public:
    Lucky() : Enhancement("Lucky") {}
    ~Lucky() = default;

    void on_count(GameData& data)
    {  // TODO: Add RNG to randomly add mult and/or money
    }
};