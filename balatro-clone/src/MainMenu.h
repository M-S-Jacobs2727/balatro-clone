#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Button.h"
#include "Layer.h"

class MainMenu : public Core::Layer
{
public:
    MainMenu();
    virtual ~MainMenu() = default;

    virtual bool onEvent(const sf::Event event) override;

    virtual void onUpdate(float ts) override;
    virtual void onRender() override;

private:
    bool onMouseButtonPressed(const sf::Event::MouseButtonPressed event);

private:
    std::unique_ptr<Button> quitButton_ = nullptr;
    std::unique_ptr<Button> newGameButton_ = nullptr;
};