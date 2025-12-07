#pragma once

#include <string_view>

#include <SFML/Graphics.hpp>

#include "Rank.h"
#include "Suit.h"

// Enhacements: Bonus, Mult, Glass, Lucky, Stone, Steel, Gold, Wild
class Enhancement
{
public:
    Enhancement(std::string_view name);
    ~Enhancement();

    std::string_view get_name() const { return name_; }

    virtual void on_count() {}
    virtual void after_count() {}
    virtual bool is_suit(Suit suit) const { return false; }
    virtual bool is_rank(Rank rank) const { return false; }

private:
    std::string_view name_;
    sf::Texture texture_;
};