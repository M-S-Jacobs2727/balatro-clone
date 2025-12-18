#include "MainMenu.h"

#include "Application.h"
#include "Run.h"

MainMenu::MainMenu()
{
    newGameButton_ =
        std::make_unique<Button>(sf::Vector2f(0.1f, 0.42f), sf::Vector2f(0.2f, 0.2f), "textures/Button.png",
                                 "shaders/Texture.frag.glsl", "shaders/Transform.vert.glsl");
    quitButton_ = std::make_unique<Button>(sf::Vector2f(0.1f, 0.2f), sf::Vector2f(0.2f, 0.2f), "textures/Button.png",
                                           "shaders/Texture.frag.glsl", "shaders/Transform.vert.glsl");
}

bool MainMenu::onEvent(const sf::Event event)
{
    const auto* mouseButtonPressedEvent = event.getIf<sf::Event::MouseButtonPressed>();
    if (mouseButtonPressedEvent)
    {
        return onMouseButtonPressed(*mouseButtonPressedEvent);
    }
    return false;
}

void MainMenu::onUpdate(float ts) {}

void MainMenu::onRender()
{
    auto& window = *Core::Application::get().getWindow();
    newGameButton_->render(window);
    quitButton_->render(window);
}

bool MainMenu::onMouseButtonPressed(const sf::Event::MouseButtonPressed event)
{
    if (event.button == sf::Mouse::Button::Left)
    {
        if (newGameButton_->isHovered())
        {
            transitionTo<Run>();
            return true;
        }
        if (quitButton_->isHovered())
        {
            Core::Application::get().getWindow()->close();
        }
    }
    return false;
}