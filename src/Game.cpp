#include "Game.h"

#include <iostream>

#include "states/MenuState.h"

Game::Game() : stateMachine_(), gameData_(), window_(sf::VideoMode({800, 600}), "Balatro Clone"), clock_()
{
    // TODO: Configure window settings
    // window_.setFramerateLimit(60);
    // window_.setVerticalSyncEnabled(true);
}

Game::~Game() {}

void Game::run()
{
    std::cout << "Game starting..." << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "- Press ENTER/SPACE to progress through states" << std::endl;
    std::cout << "- Press ESC to return to menu from any state" << std::endl;
    std::cout << "- Close window to quit" << std::endl;
    std::cout << std::endl;

    // Initialize with MenuState
    stateMachine_.setState(std::make_unique<MenuState>(), gameData_);

    // Main game loop
    while (window_.isOpen())
    {
        processInput();
        update();
        render();
    }

    std::cout << "Game shutting down..." << std::endl;
}

void Game::processInput()
{
    // Poll all events
    while (const std::optional event = window_.pollEvent())
    {
        // Handle window close
        if (event->is<sf::Event::Closed>())
        {
            window_.close();
            return;
        }

        // Pass event to state machine for game-specific handling
        stateMachine_.handleInput(*event, gameData_);
    }
}

void Game::update()
{
    // Get delta time
    float deltaTime = clock_.restart().asSeconds();

    // Update game state
    stateMachine_.update(deltaTime, gameData_);
}

void Game::render()
{
    // Delegate rendering to the state machine
    stateMachine_.render(window_, gameData_);
}
