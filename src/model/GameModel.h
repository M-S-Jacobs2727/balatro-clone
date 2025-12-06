#pragma once

#include "GameState.h"

class GameModel
{
   public:
    GameModel();
    ~GameModel();

    // State machine methods
    void transitionTo(GameState newState);
    GameState getCurrentState() const;
    bool canTransition(GameState newState) const;

    // Game data accessors (TODO: Implement these based on your game design)
    int getPlayerCurrency() const;
    void setPlayerCurrency(int currency);

    int getPlayerHealth() const;
    void setPlayerHealth(int health);

    int getCurrentLevel() const;
    void setCurrentLevel(int level);

    // TODO: Add more game data accessors as needed:
    // - Shop inventory
    // - Player stats (attack, defense, etc.)
    // - Level progression data
    // - Unlocked levels
    // - etc.

   private:
    GameState currentState_;

    // Game data members (TODO: Expand based on your game design)
    int playerCurrency_;
    int playerHealth_;
    int currentLevel_;

    // TODO: Add more game data members:
    // std::vector<Item> shopInventory_;
    // std::vector<bool> unlockedLevels_;
    // PlayerStats stats_;
    // etc.
};
