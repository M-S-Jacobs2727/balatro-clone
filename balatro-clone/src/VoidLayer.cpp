#include "VoidLayer.h"

#include "AppLayer.h"
#include "Application.h"

void VoidLayer::onUpdate(float ts)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
    {
        transitionTo<AppLayer>();
    }
}

void VoidLayer::onRender()
{
    sf::RenderWindow& window = *Core::Application::get().getWindow();
    window.clear(sf::Color(150, 20, 50, 255));
}