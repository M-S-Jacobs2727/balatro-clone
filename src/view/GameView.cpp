#include "GameView.h"

#include <iostream>

GameView::GameView()
{
    // TODO: Load fonts, textures, and other resources
    // Example:
    // if (!font_.loadFromFile("assets/fonts/arial.ttf")) {
    //     std::cerr << "Failed to load font!" << std::endl;
    // }
}

GameView::~GameView()
{
    // TODO: Cleanup resources if needed
}

void GameView::render(const GameModel& model, sf::RenderWindow& window)
{
    // Clear window
    window.clear(sf::Color::Black);

    // Route to appropriate render method based on current state
    switch (model.getCurrentState())
    {
        case GameState::MENU:
            renderMenu(model, window);
            break;
        case GameState::LEVEL_SELECTION:
            renderLevelSelection(model, window);
            break;
        case GameState::SHOP:
            renderShop(model, window);
            break;
        case GameState::LEVEL:
            renderLevel(model, window);
            break;
    }

    // Display everything
    window.display();
}

void GameView::renderMenu(const GameModel& model, sf::RenderWindow& window)
{
    // TODO: Implement menu rendering
    // Examples:
    // - Draw title text
    // - Draw "Start Game" button
    // - Draw "Options" button
    // - Draw "Quit" button

    std::cout << "Rendering MENU state" << std::endl;
}

void GameView::renderLevelSelection(const GameModel& model, sf::RenderWindow& window)
{
    // TODO: Implement level selection rendering
    // Examples:
    // - Draw available levels
    // - Show locked/unlocked status
    // - Display level previews or stats
    // - Draw back button

    std::cout << "Rendering LEVEL_SELECTION state" << std::endl;
}

void GameView::renderShop(const GameModel& model, sf::RenderWindow& window)
{
    // TODO: Implement shop rendering
    // Examples:
    // - Draw shop items/cards
    // - Display prices
    // - Show player currency
    // - Draw buy buttons
    // - Draw continue button

    std::cout << "Rendering SHOP state" << std::endl;
    std::cout << "Player Currency: " << model.getPlayerCurrency() << std::endl;
}

void GameView::renderLevel(const GameModel& model, sf::RenderWindow& window)
{
    // TODO: Implement level/gameplay rendering
    // Examples:
    // - Draw cards
    // - Display player health/stats
    // - Show current score
    // - Draw game board
    // - Display enemy information

    std::cout << "Rendering LEVEL state" << std::endl;
    std::cout << "Player Health: " << model.getPlayerHealth() << std::endl;
    std::cout << "Current Level: " << model.getCurrentLevel() << std::endl;
}
