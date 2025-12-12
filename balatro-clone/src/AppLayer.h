#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Layer.h"

class AppLayer : public Core::Layer
{
public:
    AppLayer();
    virtual ~AppLayer() = default;

    virtual bool onEvent(const sf::Event event) override;

    virtual void onUpdate(float ts) override;
    virtual void onRender() override;

private:
    bool onMouseButtonPressed(const sf::Event::MouseButtonPressed event);
    bool onWindowClosed(const sf::Event::Closed event);

private:
    sf::Shader shader_;
    sf::VertexBuffer vertexBuffer_;

    float time_ = 0.0f;
    sf::Vector2i mousePosition_{0, 0};
    sf::Vector2f flamePosition_{0.0f, 0.0f};
};