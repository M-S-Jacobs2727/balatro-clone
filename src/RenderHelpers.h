#pragma once

#include <SFML/Graphics.hpp>

namespace RenderHelpers
{
// Common color constants
namespace Colors
{
const sf::Color MenuBackground(50, 50, 150);         // Blue
const sf::Color LevelSelectBackground(50, 150, 50);  // Green
const sf::Color LevelBackground(150, 50, 50);        // Red
const sf::Color ShopBackground(200, 200, 50);        // Yellow
}  // namespace Colors

// TODO: Add text rendering helpers
// Example: void drawText(sf::RenderWindow& window, const std::string& text, int x, int y);

// TODO: Add common UI element rendering
// Example: void drawButton(sf::RenderWindow& window, const std::string& label, int x, int y);

// TODO: Add sprite/texture loading utilities
// Example: sf::Texture& getTexture(const std::string& path);
}  // namespace RenderHelpers
