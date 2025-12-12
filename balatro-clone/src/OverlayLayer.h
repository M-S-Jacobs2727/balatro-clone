#pragma once

#include <SFML/Graphics.hpp>
#include <stdint.h>

#include "Layer.h"

class OverlayLayer : public Core::Layer
{
public:
    OverlayLayer();
    virtual ~OverlayLayer() override = default;

    virtual bool onEvent(const sf::Event event) override;

    virtual void onRender() override;

private:
    bool isButtonHovered() const;

    bool onMouseButtonPressed(const sf::Event::MouseButtonPressed event);

private:
    sf::Shader shader_;
    sf::VertexBuffer vertexBuffer_;
    sf::Texture texture_;
    sf::Vector2f buttonCenter_ = sf::Vector2f{-0.8f, -0.75f};
    sf::Vector2f buttonSize_ = sf::Vector2f{0.2604f, 0.2222f};
    sf::RenderStates renderStates_;
};