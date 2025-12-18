#include "Button.h"

#include <print>

#include "Application.h"

Button::Button(const sf::Vector2f& center, const sf::Vector2f& size, const std::string& textureFilename,
               const std::string& fragmentShaderFilename, const std::string& vertexShaderFilename)
    : buttonCenter_(center), buttonSize_(size)
{
    if (!shader_.loadFromFile(vertexShaderFilename, fragmentShaderFilename))
    {
        throw std::runtime_error("Failed to load shaders!");
    }

    if (!texture_.loadFromFile(textureFilename))
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
    std::println("Created new Button!");
}

void Button::render(sf::RenderWindow& window)
{
    // Set transform
    sf::Transform transform;
    transform.translate(buttonCenter_).scale(buttonSize_);

    // Uniforms
    shader_.setUniform("u_Transform", sf::Glsl::Mat4(transform.getMatrix()));
    shader_.setUniform("u_IsHovered", isHovered());

    // Draw with both shader and texture in RenderStates
    window.draw(vertexBuffer_, renderStates_);
}

bool Button::isHovered() const
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

void Button::setSize(const sf::Vector2f& size)
{
    buttonSize_ = size;
}

void Button::setCenter(const sf::Vector2f& center)
{
    buttonCenter_ = center;
}