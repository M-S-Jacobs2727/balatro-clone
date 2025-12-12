#include "AppLayer.h"

#include <print>

#include "Application.h"
#include "VoidLayer.h"

AppLayer::AppLayer()
{
    std::println("Created new AppLayer!");

    // Create shaders
    if (!shader_.loadFromFile("shaders/Fullscreen.vert.glsl", "shaders/Flame.frag.glsl"))
    {
        throw std::runtime_error("Failed to load shaders!");
    }
    vertexBuffer_.setUsage(sf::VertexBuffer::Usage::Static);
    vertexBuffer_.setPrimitiveType(sf::PrimitiveType::Triangles);

    sf::Vertex vertices[] = {
        {{-1.0f, -1.0f}, {}, {0.0f, 0.0f}},  // Bottom-left
        {{3.0f, -1.0f}, {}, {2.0f, 0.0f}},   // Bottom-right
        {{-1.0f, 3.0f}, {}, {0.0f, 2.0f}}    // Top-left
    };

    if (!vertexBuffer_.create(3))
    {
        throw std::runtime_error("Failed to create vertex buffer!");
    }
    if (!vertexBuffer_.update(vertices))
    {
        throw std::runtime_error("Failed to update vertex buffer!");
    }
}

bool AppLayer::onEvent(const sf::Event event)
{
    const auto* mouseButtonPressedEvent = event.getIf<sf::Event::MouseButtonPressed>();
    if (mouseButtonPressedEvent)
    {
        return onMouseButtonPressed(*mouseButtonPressedEvent);
    }
    const auto* windowClosedEvent = event.getIf<sf::Event::Closed>();
    if (windowClosedEvent)
    {
        return onWindowClosed(*windowClosedEvent);
    }

    return false;
}

void AppLayer::onUpdate(float ts)
{
    time_ += ts;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
    {
        transitionTo<VoidLayer>();
    }
}

void AppLayer::onRender()
{
    shader_.setUniform("iTime", time_);
    auto& app = Core::Application::get();

    sf::Vector2f framebufferSize = static_cast<sf::Vector2f>(app.getFramebufferSize());

    shader_.setUniform("iResolution", framebufferSize);
    shader_.setUniform("flameOrigin", flamePosition_);

    sf::RenderStates renderStates{&shader_};
    app.getWindow()->draw(vertexBuffer_, renderStates);
}

bool AppLayer::onMouseButtonPressed(const sf::Event::MouseButtonPressed event)
{
    std::println("Mouse Button Pressed in AppLayer!");
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(event.position);
    sf::Vector2f framebufferSize = static_cast<sf::Vector2f>(Core::Application::get().getFramebufferSize());
    float aspectRatio = static_cast<float>(framebufferSize.x) / static_cast<float>(framebufferSize.y);
    sf::Vector2f normalizedMousePos =
        sf::Vector2f({mousePosition.x / framebufferSize.x, mousePosition.y / framebufferSize.y}) * 2.0f -
        sf::Vector2f{1.0f, 1.0f};
    normalizedMousePos.x *= aspectRatio;
    normalizedMousePos.y *= -1.0f;
    normalizedMousePos.y += 0.7f;

    flamePosition_ = -normalizedMousePos;

    return false;
}

bool AppLayer::onWindowClosed(const sf::Event::Closed event)
{
    std::println("Window Closed!");

    return false;
}