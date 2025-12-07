#include "LevelState.h"

#include <iostream>

#include "../GameData.h"
#include "MenuState.h"
#include "ShopState.h"

LevelState::LevelState() : nextState_(nullptr) {}

LevelState::~LevelState() {}

void LevelState::onEnter(GameData& data)
{
    std::cout << "=== LEVEL " << data.currentLevel << " ===" << std::endl;
    std::cout << "Health: " << data.playerHealth << " | Currency: " << data.playerCurrency << std::endl;
    std::cout << "Press ENTER/SPACE to complete level (go to shop)" << std::endl;
    std::cout << "Press ESC to return to menu" << std::endl;
}

void LevelState::onExit(GameData& data)
{
    // TODO: Save level results
    // TODO: Cleanup level resources
}

void LevelState::handleInput(const sf::Event& event, GameData& data)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();

        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Level complete - transitioning to Shop" << std::endl;
            // TODO: Award currency/rewards for completing level
            nextState_ = std::make_unique<ShopState>();
        }
        else if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            std::cout << "Returning to menu" << std::endl;
            nextState_ = std::make_unique<MenuState>();
        }
    }

    // TODO: Add gameplay input handling
    // - Card selection and playing
    // - Player actions
    // - Pause menu
}

void LevelState::update(float deltaTime, GameData& data)
{
    // TODO: Update game logic
    // - Enemy AI
    // - Card effects
    // - Check win/lose conditions
    // - Update animations
    // - Update timers
}

void LevelState::render(sf::RenderWindow& window, const GameData& data)
{
    window.clear(sf::Color::Red);

    // TODO: Draw game board
    // TODO: Draw player hand/cards
    // TODO: Draw enemy
    // TODO: Draw UI (health, currency, etc.)
    // TODO: Draw game effects/animations

    window.display();
}

std::unique_ptr<State> LevelState::getNextState()
{
    return std::move(nextState_);
}
