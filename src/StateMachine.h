#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "GameData.h"
#include "states/State.h"

class StateMachine
{
public:
    StateMachine();
    ~StateMachine();

    // Set the current state (handles onExit/onEnter calls)
    void setState(std::unique_ptr<State> newState, GameData& data);

    // Delegate to current state
    void handleInput(const sf::Event& event, GameData& data);
    void update(float deltaTime, GameData& data);
    void render(sf::RenderWindow& window, const GameData& data);

private:
    std::unique_ptr<State> currentState_;

    // Check for state transitions and handle them
    void checkTransition(GameData& data);
};
