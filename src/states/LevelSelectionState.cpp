#include "LevelSelectionState.h"

#include <iostream>

#include "../GameData.h"
#include "LevelState.h"
#include "MenuState.h"

LevelSelectionState::LevelSelectionState() : nextState_(nullptr) {}

LevelSelectionState::~LevelSelectionState() {}

void LevelSelectionState::onEnter(GameData& data)
{
    std::cout << "=== LEVEL SELECTION ===" << std::endl;
    std::cout << "Current Round: " << data.round << std::endl;
    std::cout << "Press ENTER/SPACE to select level" << std::endl;
    std::cout << "Press ESC to return to menu" << std::endl;
}

void LevelSelectionState::onExit(GameData& data)
{
    // TODO: Cleanup level selection resources
}

void LevelSelectionState::handleInput(const sf::Event& event, GameData& data)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();

        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Level selected - transitioning to Level" << std::endl;
            nextState_ = std::make_unique<LevelState>();
        }
        else if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            std::cout << "Returning to menu" << std::endl;
            nextState_ = std::make_unique<MenuState>();
        }
    }

    // TODO: Add mouse input for level selection buttons
    // TODO: Add arrow keys for level navigation
    // TODO: Check if selected level is unlocked
}

void LevelSelectionState::update(float deltaTime, GameData& data)
{
    // TODO: Add level preview animations
    // TODO: Update level statistics display
}

void LevelSelectionState::render(sf::RenderWindow& window, const GameData& data)
{
    window.clear(sf::Color::Green);

    // TODO: Draw level selection grid/list
    // TODO: Draw level previews
    // TODO: Draw level statistics (best score, unlock status, etc.)
    // TODO: Draw player stats (currency, health, etc.)

    window.display();
}

std::unique_ptr<State> LevelSelectionState::getNextState()
{
    return std::move(nextState_);
}
