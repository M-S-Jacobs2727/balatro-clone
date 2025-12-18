#include "Run.h"

#include <print>

Run::Run()
{
    std::println("Created new Run!");
}

void Run::onUpdate(float ts) {}

void Run::onRender() {}

bool Run::onEvent(const sf::Event event)
{
    return false;
}