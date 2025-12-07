#pragma once

#include <optional>

#include <SFML/Graphics.hpp>

#include "Enhancement.h"
#include "Rank.h"
#include "Suit.h"

class PlayingCard
{
public:
    PlayingCard();
    ~PlayingCard();

    Suit get_suit() const { return suit_; }
    Rank get_rank() const { return rank_; }
    bool is_face_up() const { return is_face_up_; }
    std::optional<Enhancement> get_enhancement() const { return enhancement_; }
    bool is_suit(Suit suit) const { return suit_ == suit; }
    bool is_rank(Rank rank) const { return rank_ == rank; }

    void set_suit(Suit suit) { suit_ = suit; }
    void set_rank(Rank rank) { rank_ = rank; }
    void set_face_up(bool is_face_up) { is_face_up_ = is_face_up; }
    void set_enhancement(std::optional<Enhancement> enhancement) { enhancement_ = enhancement; }

private:
    sf::Texture texture_;
    Suit suit_;
    Rank rank_;
    bool is_face_up_;
    std::optional<Enhancement> enhancement_;
};