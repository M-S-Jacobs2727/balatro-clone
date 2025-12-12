#pragma once

#include <memory>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Layer.h"

namespace Core
{

struct WindowSpecification
{
    std::string title;
    uint32_t width = 800;
    uint32_t height = 600;
    bool vsync = true;
};

struct ApplicationSpecification
{
    std::string name;
    WindowSpecification windowSpec;
};

class Application
{
public:
    Application(const ApplicationSpecification& specification);
    ~Application();

    void run();

    void raiseEvent(const sf::Event event);

    template <typename TLayer>
        requires(std::is_base_of_v<Layer, TLayer>)
    void pushLayer()
    {
        layerStack_.push_back(std::make_unique<TLayer>());
    }

    template <typename TLayer>
        requires(std::is_base_of_v<Layer, TLayer>)
    TLayer* getLayer()
    {
        for (const auto& layer : layerStack_)
        {
            if (auto casted = dynamic_cast<TLayer*>(layer.get()))
                return casted;
        }
        return nullptr;
    }

    sf::Vector2u getFramebufferSize() const;

    std::shared_ptr<sf::RenderWindow> getWindow() const { return window_; }

    static Application& get();
    float getTime() const;

private:
    void init();

private:
    ApplicationSpecification spec_;
    std::shared_ptr<sf::RenderWindow> window_;
    bool running_ = false;
    sf::Clock clock_;

    std::vector<std::unique_ptr<Layer>> layerStack_;

    friend class Layer;
};

}  // namespace Core