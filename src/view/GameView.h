#pragma once

#include <SFML/Graphics.hpp>

#include "../model/GameModel.h"

class GameView
{
   public:
    GameView();
    ~GameView();

    // Main render method - routes to state-specific rendering
    void render(const GameModel& model, sf::RenderWindow& window);

   private:
    // State-specific render methods
    void renderMenu(const GameModel& model, sf::RenderWindow& window);
    void renderLevelSelection(const GameModel& model, sf::RenderWindow& window);
    void renderShop(const GameModel& model, sf::RenderWindow& window);
    void renderLevel(const GameModel& model, sf::RenderWindow& window);

    // TODO: Add shared rendering resources (fonts, textures, etc.)
    // sf::Font font_;
    // sf::Texture backgroundTexture_;
    // etc.
};
