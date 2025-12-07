#include "StateMachine.h"

StateMachine::StateMachine() : currentState_(nullptr) {}

StateMachine::~StateMachine() {}

void StateMachine::setState(std::unique_ptr<State> newState, GameData& data)
{
    // Exit current state if one exists
    if (currentState_)
    {
        currentState_->onExit(data);
    }

    // Set new state
    currentState_ = std::move(newState);

    // Enter new state
    if (currentState_)
    {
        currentState_->onEnter(data);
    }
}

void StateMachine::handleInput(const sf::Event& event, GameData& data)
{
    if (currentState_)
    {
        currentState_->handleInput(event, data);
    }
}

void StateMachine::update(float deltaTime, GameData& data)
{
    if (currentState_)
    {
        currentState_->update(deltaTime, data);

        // Check for state transitions
        checkTransition(data);
    }
}

void StateMachine::render(sf::RenderWindow& window, const GameData& data)
{
    if (currentState_)
    {
        currentState_->render(window, data);
    }
}

void StateMachine::checkTransition(GameData& data)
{
    if (currentState_)
    {
        std::unique_ptr<State> nextState = currentState_->getNextState();
        if (nextState)
        {
            setState(std::move(nextState), data);
        }
    }
}
