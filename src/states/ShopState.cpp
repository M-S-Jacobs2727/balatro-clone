#include "ShopState.h"

#include <iostream>

#include "../GameData.h"
#include "LevelSelectionState.h"
#include "MenuState.h"

ShopState::ShopState() : nextState_(nullptr) {}

ShopState::~ShopState() {}

void ShopState::onEnter(GameData& data)
{
    std::cout << "=== SHOP ===" << std::endl;
    std::cout << "Currency: " << data.playerCurrency << std::endl;
    std::cout << "Press ENTER/SPACE to continue (return to level selection)" << std::endl;
    std::cout << "Press ESC to return to menu" << std::endl;
}

void ShopState::onExit(GameData& data)
{
    // TODO: Save shop purchases
    // TODO: Cleanup shop resources
}

void ShopState::handleInput(const sf::Event& event, GameData& data)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();

        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Leaving shop - transitioning to Level Selection" << std::endl;
            nextState_ = std::make_unique<LevelSelectionState>();
        }
        else if (keyEvent->code == sf::Keyboard::Key::Escape)
        {
            std::cout << "Returning to menu" << std::endl;
            nextState_ = std::make_unique<MenuState>();
        }
    }

    // TODO: Add shop item selection and purchase
    // TODO: Add mouse input for clicking items
    // TODO: Validate currency before purchase
}

void ShopState::update(float deltaTime, GameData& data)
{
    // TODO: Add shop animations
    // TODO: Update item previews
}

void ShopState::render(sf::RenderWindow& window, const GameData& data)
{
    window.clear(sf::Color::Yellow);

    // TODO: Draw shop inventory
    // TODO: Draw item prices
    // TODO: Draw player currency
    // TODO: Draw purchase confirmation UI

    window.display();
}

std::unique_ptr<State> ShopState::getNextState()
{
    return std::move(nextState_);
}
