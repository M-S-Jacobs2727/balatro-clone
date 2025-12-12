#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

namespace Core
{

class Layer
{
public:
    virtual ~Layer() = default;

    virtual bool onEvent(const sf::Event event) { return false; }

    virtual void onUpdate(float ts) {}
    virtual void onRender() {}

    template <std::derived_from<Layer> T, typename... Args>
    void transitionTo(Args&&... args)
    {
        queueTransition(std::move(std::make_unique<T>(std::forward<Args>(args)...)));
    }

private:
    void queueTransition(std::unique_ptr<Layer> layer);
};

}  // namespace Core