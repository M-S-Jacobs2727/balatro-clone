#include "Game.h"

#include <iostream>

Game::Game()
    : model_(std::make_unique<GameModel>()),
      view_(std::make_unique<GameView>()),
      controller_(std::make_unique<GameController>()),
      window_(sf::VideoMode({800, 600}), "Balatro Clone")
{
    // TODO: Configure window settings
    // window_.setFramerateLimit(60);
    // window_.setVerticalSyncEnabled(true);
}

Game::~Game()
{
    // Unique pointers will automatically clean up
}

void Game::run()
{
    std::cout << "Game starting..." << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "- Press ENTER/SPACE to progress through states" << std::endl;
    std::cout << "- Press ESC to return to menu from any state" << std::endl;
    std::cout << "- Close window to quit" << std::endl;
    std::cout << std::endl;

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

        // Pass event to controller for game-specific handling
        controller_->handleInput(*event, *model_);
    }
}

void Game::update()
{
    // TODO: Add game logic updates here
    // Examples:
    // - Update animations
    // - Update enemy AI
    // - Check win/lose conditions
    // - Update timers
    // etc.
}

void Game::render()
{
    // Delegate rendering to the view
    view_->render(*model_, window_);
}
