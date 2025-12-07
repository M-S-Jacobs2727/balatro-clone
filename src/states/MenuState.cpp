#include "MenuState.h"

#include <iostream>

#include "../GameData.h"
#include "LevelSelectionState.h"

MenuState::MenuState() : nextState_(nullptr) {}

MenuState::~MenuState() {}

void MenuState::onEnter(GameData& data)
{
    std::cout << "=== MENU ===" << std::endl;
    std::cout << "Press ENTER/SPACE to start game" << std::endl;
    std::cout << "Press ESC to quit (close window)" << std::endl;
}

void MenuState::onExit(GameData& data)
{
    // TODO: Cleanup menu resources if needed
}

void MenuState::handleInput(const sf::Event& event, GameData& data)
{
    if (event.is<sf::Event::KeyPressed>())
    {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::Enter || keyEvent->code == sf::Keyboard::Key::Space)
        {
            std::cout << "Starting game - transitioning to Level Selection" << std::endl;
            nextState_ = std::make_unique<LevelSelectionState>();
        }
    }

    // TODO: Add mouse input for menu buttons
    // TODO: Add menu navigation (up/down arrows)
}

void MenuState::update(float deltaTime, GameData& data)
{
    // TODO: Add menu animations
    // TODO: Add menu music/sound effects
}

void MenuState::render(sf::RenderWindow& window, const GameData& data)
{
    window.clear(sf::Color::Blue);

    // TODO: Draw menu title
    // TODO: Draw menu buttons (Start, Options, Quit)
    // TODO: Draw game logo/art

    window.display();
}

std::unique_ptr<State> MenuState::getNextState()
{
    return std::move(nextState_);
}
