#pragma once

#include <SFML/Graphics.hpp>

#include "GameData.h"
#include "StateMachine.h"

class Game
{
public:
    Game();
    ~Game();

    // Main game loop
    void run();

private:
    // State machine
    StateMachine stateMachine_;

    // Shared game data
    GameData gameData_;

    // SFML window
    sf::RenderWindow window_;

    // Delta time tracking
    sf::Clock clock_;

    // Game loop helpers
    void processInput();
    void update();
    void render();
};
