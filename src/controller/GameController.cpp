#include "GameController.h"

#include <iostream>

GameController::GameController()
{
    // TODO: Initialize controller state if needed
}

GameController::~GameController()
{
    // TODO: Cleanup if needed
}

void GameController::handleInput(const sf::Event& event, GameModel& model)
{
    // Check for global menu access (Escape key from any state)
    if (isMenuRequest(event) && model.getCurrentState() != GameState::MENU)
    {
        model.transitionTo(GameState::MENU);
        return;
    }

    // Route to appropriate input handler based on current state
    switch (model.getCurrentState())
    {
        case GameState::MENU:
            handleMenuInput(event, model);
            break;
        case GameState::LEVEL_SELECTION:
            handleLevelSelectionInput(event, model);
            break;
        case GameState::SHOP:
            handleShopInput(event, model);
            break;
        case GameState::LEVEL:
            handleLevelInput(event, model);
            break;
    }
}

void GameController::handleMenuInput(const sf::Event& event, GameModel& model)
{
    // TODO: Implement menu input handling
    // Examples:
    // - Check for button clicks or key presses
    // - "Start Game" -> transition to LEVEL_SELECTION
    // - "Options" -> show options menu
    // - "Quit" -> exit game

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Starting game - transitioning to Level Selection" << std::endl;
            model.transitionTo(GameState::LEVEL_SELECTION);
        }
    }
}

void GameController::handleLevelSelectionInput(const sf::Event& event, GameModel& model)
{
    // TODO: Implement level selection input handling
    // Examples:
    // - Check for level selection clicks
    // - Validate if level is unlocked
    // - Load selected level
    // - Transition to LEVEL state

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Level selected - transitioning to Level" << std::endl;
            model.transitionTo(GameState::LEVEL);
        }
    }
}

void GameController::handleShopInput(const sf::Event& event, GameModel& model)
{
    // TODO: Implement shop input handling
    // Examples:
    // - Check for item selection and purchase
    // - Validate currency
    // - Update player inventory
    // - "Continue" button -> transition to LEVEL_SELECTION

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Leaving shop - transitioning to Level Selection" << std::endl;
            model.transitionTo(GameState::LEVEL_SELECTION);
        }
    }
}

void GameController::handleLevelInput(const sf::Event& event, GameModel& model)
{
    // TODO: Implement level/gameplay input handling
    // Examples:
    // - Card selection and playing
    // - Player actions (attack, defend, etc.)
    // - Handle game over
    // - Handle level completion -> transition to SHOP

    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Level complete - transitioning to Shop" << std::endl;
            model.transitionTo(GameState::SHOP);
        }
    }
}

bool GameController::isMenuRequest(const sf::Event& event) const
{
    // Check if Escape key is pressed (global menu access)
    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        return keyEvent->code == sf::Keyboard::Key::Escape;
    }
    return false;
}
