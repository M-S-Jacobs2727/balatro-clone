#include "Layer.h"

#include "Application.h"

namespace Core
{

void Layer::queueTransition(std::unique_ptr<Layer> toLayer)
{
    // TODO: don't do this
    auto& layerStack = Application::get().layerStack_;
    for (auto& layer : layerStack)
    {
        if (layer.get() == this)
        {
            layer = std::move(toLayer);
            return;
        }
    }
}

}  // namespace Core