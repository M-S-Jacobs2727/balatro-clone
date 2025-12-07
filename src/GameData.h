#pragma once

// GameData holds all shared game state that persists across state transitions
struct GameData
{
    // Player stats
    int playerCurrency = 100;
    int playerHealth = 100;
    int currentLevel = 1;

    // TODO: Add more game data as needed:
    // - Shop inventory
    // - Player inventory/deck
    // - Unlocked levels
    // - High scores
    // - Game progression flags
    // etc.
};
