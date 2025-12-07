#pragma once

#include <string_view>

class Blind
{
public:
    virtual ~Blind() = default;

    // Getters
    double get_multiplier() const { return multiplier; }
    std::string_view get_name() const { return name; }

    // Optional callbacks (can be overridden)
    virtual void on_round_start() {}
    virtual void on_hand_played() {}
    virtual void on_first_draw() {}
    virtual void on_redraw() {}
    virtual void on_discard() {}
    virtual void on_win() {}
    virtual void on_joker_sold() {}

protected:
    Blind(double mult, std::string_view n) : multiplier(mult), name(n) {}

private:
    const double multiplier;
    std::string_view name;
};