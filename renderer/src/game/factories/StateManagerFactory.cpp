//
// Created by rune-suy on 11/4/25.
//

#include "game/factories/StateManagerFactory.h"
#include "game/factories/DefaultStateFactory.h"
#include "game/states/MenuState.h"
#include "core/states/IStateInputHandler.h"
#include "core/states/IStateUpdateHandler.h"

namespace renderer
{
    std::unique_ptr<StateManager> StateManagerFactory::createStateManager(std::unique_ptr<IStateFactory> stateFactory)
    {
        auto menuState = stateFactory->createMenuState();
        return std::make_unique<StateManager>(std::move(menuState), std::move(stateFactory));
    }
} // renderer
