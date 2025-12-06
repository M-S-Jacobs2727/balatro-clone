#include "GameModel.h"

#include <iostream>

GameModel::GameModel()
    : currentState_(GameState::MENU),
      playerCurrency_(100)  // TODO: Set initial values based on your game design
      ,
      playerHealth_(100),
      currentLevel_(1)
{
    // TODO: Initialize other game data members
}

GameModel::~GameModel()
{
    // TODO: Cleanup if needed
}

void GameModel::transitionTo(GameState newState)
{
    // Validate transition
    if (!canTransition(newState))
    {
        std::cerr << "Invalid state transition attempted!" << std::endl;
        return;
    }

    // TODO: Add any state exit logic here (save data, cleanup, etc.)

    currentState_ = newState;

    // TODO: Add any state entry logic here (load data, initialize, etc.)
    std::cout << "Transitioned to state: " << static_cast<int>(newState) << std::endl;
}

GameState GameModel::getCurrentState() const
{
    return currentState_;
}

bool GameModel::canTransition(GameState newState) const
{
    // Menu is accessible from any state
    if (newState == GameState::MENU)
    {
        return true;
    }

    // State transition logic based on current state
    switch (currentState_)
    {
        case GameState::MENU:
            // From menu, can only go to level selection
            return newState == GameState::LEVEL_SELECTION;

        case GameState::LEVEL_SELECTION:
            // From level selection, can go to level or back to menu
            return newState == GameState::LEVEL || newState == GameState::MENU;

        case GameState::LEVEL:
            // From level, can go to shop or back to menu
            return newState == GameState::SHOP || newState == GameState::MENU;

        case GameState::SHOP:
            // From shop, can go back to level selection or menu
            return newState == GameState::LEVEL_SELECTION || newState == GameState::MENU;

        default:
            return false;
    }
}

// Game data accessor implementations
int GameModel::getPlayerCurrency() const
{
    return playerCurrency_;
}

void GameModel::setPlayerCurrency(int currency)
{
    playerCurrency_ = currency;
    // TODO: Add validation, limits, or events as needed
}

int GameModel::getPlayerHealth() const
{
    return playerHealth_;
}

void GameModel::setPlayerHealth(int health)
{
    playerHealth_ = health;
    // TODO: Add validation, check for game over condition, etc.
}

int GameModel::getCurrentLevel() const
{
    return currentLevel_;
}

void GameModel::setCurrentLevel(int level)
{
    currentLevel_ = level;
    // TODO: Add validation, unlock logic, etc.
}
