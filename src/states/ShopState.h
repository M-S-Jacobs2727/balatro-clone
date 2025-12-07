#pragma once

#include <memory>

#include "../states/State.h"

class ShopState : public State
{
public:
    ShopState();
    ~ShopState() override;

    void onEnter(GameData& data) override;
    void onExit(GameData& data) override;
    void handleInput(const sf::Event& event, GameData& data) override;
    void update(float deltaTime, GameData& data) override;
    void render(sf::RenderWindow& window, const GameData& data) override;
    std::unique_ptr<State> getNextState() override;

private:
    std::unique_ptr<State> nextState_;
};
