#ifndef GAME_H
#define GAME_H

#include <memory>

#include <SFML/Graphics.hpp>

#include "controller/GameController.h"
#include "model/GameModel.h"
#include "view/GameView.h"

class Game
{
   public:
    Game();
    ~Game();

    // Main game loop
    void run();

   private:
    // MVC components
    std::unique_ptr<GameModel> model_;
    std::unique_ptr<GameView> view_;
    std::unique_ptr<GameController> controller_;

    // SFML window
    sf::RenderWindow window_;

    // Game loop helpers
    void processInput();
    void update();
    void render();
};
#endif  // GAME_H
