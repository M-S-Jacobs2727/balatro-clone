#include "OverlayLayer.h"

#include <print>

#include <SFML/System/Vector2.hpp>

#include "AppLayer.h"
#include "Application.h"
#include "VoidLayer.h"

OverlayLayer::OverlayLayer()
{
    std::println("Created new OverlayLayer!");

    // Create shaders
    if (!shader_.loadFromFile("shaders/Transform.vert.glsl", "shaders/Texture.frag.glsl"))
    {
        throw std::runtime_error("Failed to load shaders!");
    }

    // Load texture
    if (!texture_.loadFromFile("textures/Button.png"))
    {
        throw std::runtime_error("Failed to load texture!");
    }
    sf::Vector2f imageSize = static_cast<sf::Vector2f>(texture_.getSize());
    std::println("Image size: {} x {}", imageSize.x, imageSize.y);

    // Create vertex buffer
    vertexBuffer_.setPrimitiveType(sf::PrimitiveType::TriangleFan);

    // SFML uses pixel coordinates for texture coords, not normalized 0-1
    // Flip Y coordinates to fix upside-down texture
    sf::Vertex vertices[] = {
        {{-0.5f, -0.5f}, sf::Color::White, {0.0f, imageSize.y}},        // Bottom-left
        {{0.5f, -0.5f}, sf::Color::White, {imageSize.x, imageSize.y}},  // Bottom-right
        {{0.5f, 0.5f}, sf::Color::White, {imageSize.x, 0.0f}},          // Top-right
        {{-0.5f, 0.5f}, sf::Color::White, {0.0f, 0.0f}}                 // Top-left
    };

    if (!vertexBuffer_.create(4))
    {
        throw std::runtime_error("Failed to create vertex buffer!");
    }
    if (!vertexBuffer_.update(vertices))
    {
        throw std::runtime_error("Failed to update vertex buffer!");
    }

    // Set uniforms
    sf::Transform transform;
    transform.translate(buttonCenter_).scale(buttonSize_);
    shader_.setUniform("u_Transform", sf::Glsl::Mat4(transform.getMatrix()));
    // shader_.setUniform("u_Texture", texture_);
    shader_.setUniform("u_IsHovered", false);

    renderStates_.texture = &texture_;
    renderStates_.shader = &shader_;
}

bool OverlayLayer::onEvent(const sf::Event event)
{
    const auto* mouseButtonPressedEvent = event.getIf<sf::Event::MouseButtonPressed>();
    if (mouseButtonPressedEvent)
    {
        return onMouseButtonPressed(*mouseButtonPressedEvent);
    }

    return false;
}

void OverlayLayer::onRender()
{
    // Set transform
    sf::Transform transform;
    transform.translate(buttonCenter_).scale(buttonSize_);

    // Uniforms
    shader_.setUniform("u_Transform", sf::Glsl::Mat4(transform.getMatrix()));
    shader_.setUniform("u_IsHovered", isButtonHovered());
    // shader_.setUniform("u_Texture", sf::Shader::CurrentTexture);

    // Draw with both shader and texture in RenderStates
    Core::Application::get().getWindow()->draw(vertexBuffer_, renderStates_);
}

bool OverlayLayer::isButtonHovered() const
{
    auto& app = Core::Application::get();
    sf::Vector2f framebufferSize = sf::Vector2f(app.getFramebufferSize());
    sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*app.getWindow()));
    sf::Vector2f normalizedMousePos =
        sf::Vector2f{mousePos.x / framebufferSize.x, mousePos.y / framebufferSize.y} * 2.0f - sf::Vector2f{1.0f, 1.0f};
    normalizedMousePos.y *= -1.0f;

    return normalizedMousePos.x > (buttonCenter_.x - buttonSize_.x * 0.5f) &&
           normalizedMousePos.x < (buttonCenter_.x + buttonSize_.x * 0.5f) &&
           normalizedMousePos.y > (buttonCenter_.y - buttonSize_.y * 0.5f) &&
           normalizedMousePos.y < (buttonCenter_.y + buttonSize_.y * 0.5f);
}

bool OverlayLayer::onMouseButtonPressed(const sf::Event::MouseButtonPressed event)
{
    if (!isButtonHovered())
        return false;

    std::println("Mouse Button Pressed in OverlayLayer!");

    auto& app = Core::Application::get();
    auto voidLayer = app.getLayer<VoidLayer>();
    if (voidLayer)
    {
        voidLayer->transitionTo<AppLayer>();
    }
    else
    {
        auto appLayer = app.getLayer<AppLayer>();
        appLayer->transitionTo<VoidLayer>();
    }

    return true;
}