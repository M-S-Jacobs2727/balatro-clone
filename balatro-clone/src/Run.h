#pragma once

#include "Layer.h"

class Run : public Core::Layer
{
public:
    Run();
    virtual ~Run() = default;

    virtual bool onEvent(const sf::Event event) override;

    virtual void onUpdate(float ts) override;
    virtual void onRender() override;
};