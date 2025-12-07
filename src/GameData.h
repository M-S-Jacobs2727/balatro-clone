#pragma once

#include <array>
#include <cstdint>
#include <vector>

constexpr int32_t NUM_POKER_HANDS = 12;

enum class PokerHand : std::size_t
{
    HighCard = 0,
    Pair,
    TwoPair,
    ThreeOfAKind,
    Straight,
    Flush,
    FullHouse,
    FourOfAKind,
    StraightFlush,
    FiveOfAKind,
    FlushFive,
    FlushHouse,
};

enum class BossBlindType : std::size_t
{
    Hook = 0,
    Ox,
    House,
    Fish,
    Wheel,
    Flint,
    Needle,
    Wall,
    Psychic,
    Eye,
    Mouth,
    Diamond,
    Head,
    Goad,
    Club,
    Tooth,
    Plant,
    Mark,
    Pillar,
    Manacle,
    Arm,
    Water,
    Serpent,
};

struct PokerHandStats
{
    std::array<int32_t, NUM_POKER_HANDS> num_hands_played;
    std::array<int32_t, NUM_POKER_HANDS> level{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};

// GameData holds all shared game state that persists across state transitions
struct GameData
{
    int32_t ante = 1;
    int32_t round = 1;
    int32_t money = 4;
    int32_t max_num_hands = 4;
    int32_t max_num_discards = 3;
    int32_t max_num_jokers = 5;
    int32_t max_num_consumables = 2;
    int32_t max_hand_size = 8;
    PokerHandStats poker_hand_stats;
    std::vector<BossBlindType> boss_blind_pool;
};
