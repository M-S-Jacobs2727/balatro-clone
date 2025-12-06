#pragma once

#include <SFML/Graphics.hpp>

#include "../model/GameModel.h"

class GameController
{
   public:
    GameController();
    ~GameController();

    // Main input handler - routes to state-specific handlers
    void handleInput(const sf::Event& event, GameModel& model);

   private:
    // State-specific input handlers
    void handleMenuInput(const sf::Event& event, GameModel& model);
    void handleLevelSelectionInput(const sf::Event& event, GameModel& model);
    void handleShopInput(const sf::Event& event, GameModel& model);
    void handleLevelInput(const sf::Event& event, GameModel& model);

    // Helper method to check for menu access (Escape key from any state)
    bool isMenuRequest(const sf::Event& event) const;
};
