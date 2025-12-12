#include "Application.h"

#include <cassert>

#include <SFML/Graphics.hpp>

namespace Core
{

static Application* APPLICATION = nullptr;

Application::Application(const ApplicationSpecification& specification) : spec_(specification)
{
    APPLICATION = this;

    // Set window title to app name if empty
    if (spec_.windowSpec.title.empty())
        spec_.windowSpec.title = spec_.name;
}

Application::~Application() = default;

void Application::init()
{
    window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode({spec_.windowSpec.width, spec_.windowSpec.height}),
                                                 spec_.windowSpec.title, sf::Style::Default);
    window_->setVerticalSyncEnabled(spec_.windowSpec.vsync);
}

void Application::run()
{
    init();
    running_ = true;

    float lastTime = getTime();

    // Main Application loop
    while (window_->isOpen())
    {
        while (const std::optional event = window_->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window_->close();
            raiseEvent(*event);
        }

        window_->clear();

        float currentTime = getTime();
        float timestep = std::clamp(currentTime - lastTime, 0.001f, 0.1f);
        lastTime = currentTime;

        // Main layer update here
        for (const std::unique_ptr<Layer>& layer : layerStack_)
            layer->onUpdate(timestep);

        // NOTE: rendering can be done elsewhere (eg. render thread)
        for (const std::unique_ptr<Layer>& layer : layerStack_)
            layer->onRender();

        window_->display();
    }
}

void Application::raiseEvent(const sf::Event event)
{
    for (auto layer_it = layerStack_.rbegin(); layer_it != layerStack_.rend(); ++layer_it)
    {
        auto& layer = *layer_it;
        bool handled = layer->onEvent(event);
        if (handled)
            break;
    }
}

sf::Vector2u Application::getFramebufferSize() const
{
    return window_->getSize();
}

Application& Application::get()
{
    assert(APPLICATION);
    return *APPLICATION;
}

float Application::getTime() const
{
    return (float)clock_.getElapsedTime().asSeconds();
}

}  // namespace Core