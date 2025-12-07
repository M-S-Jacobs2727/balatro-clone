#pragma once

#include "../Enhancement.h"
#include "../GameData.h"

class Stone : public Enhancement
{
public:
    Stone() : Enhancement("Stone") {}
    ~Stone() = default;

    void on_count(GameData& data) { data.chip_score += 50; }
    bool is_suit(Suit suit) const { return false; }
    bool is_rank(Rank rank) const { return false; }
};