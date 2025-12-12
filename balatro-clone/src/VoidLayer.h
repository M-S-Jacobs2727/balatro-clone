#pragma once

#include "Layer.h"

class VoidLayer : public Core::Layer
{
public:
    VoidLayer() {}
    virtual ~VoidLayer() {}

    virtual void onUpdate(float ts) override;
    virtual void onRender() override;
};