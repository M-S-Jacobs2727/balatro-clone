#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

// Forward declaration
struct GameData;

class State
{
public:
    virtual ~State() = default;

    // Called once when entering this state
    virtual void onEnter(GameData& data) = 0;

    // Called once when exiting this state
    virtual void onExit(GameData& data) = 0;

    // Called every frame for input handling
    virtual void handleInput(const sf::Event& event, GameData& data) = 0;

    // Called every frame for game logic updates
    virtual void update(float deltaTime, GameData& data) = 0;

    // Called every frame for rendering
    virtual void render(sf::RenderWindow& window, const GameData& data) = 0;

    // Returns the next state to transition to, or nullptr if staying in current state
    virtual std::unique_ptr<State> getNextState() = 0;
};
