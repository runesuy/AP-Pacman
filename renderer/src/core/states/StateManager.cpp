//
// Created by runes on 3/11/2025.
//

#include "core/states/StateManager.h"
#include "core/states/IState.h"
#include "core/factories/IStateFactory.h"

renderer::StateManager::StateManager(std::unique_ptr<IState>&& initialState,
                                     std::unique_ptr<IStateFactory>&& stateFactory) : stateFactory(
    std::move(stateFactory))
{
    stack.push(std::move(initialState));
}

void renderer::StateManager::processInput(sf::Event& event, sf::RenderWindow& window)
{
    if (!stack.empty())
    {
        stack.top()->processInput(event, *this, window);
    }
}

void renderer::StateManager::draw(sf::RenderWindow& window)
{
    if (!stack.empty())
    {
        stack.top()->draw(window, *this);
    }
}

void renderer::StateManager::update()
{
    if (!stack.empty())
    {
        stack.top()->update(*this);
    }
}

void renderer::StateManager::pushState(std::unique_ptr<IState>&& state)
{
    stack.push(std::move(state));
}

void renderer::StateManager::popState()
{
    stack.pop();
    if (!stack.empty())
    {
        stack.top()->onManagerReActive();
    }
}

void renderer::StateManager::replaceState(std::unique_ptr<IState>&& state)
{
    stack.pop();
    stack.push(std::move(state));
    stack.top()->onManagerReActive();
}
