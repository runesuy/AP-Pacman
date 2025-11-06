//
// Created by rune-suy on 11/4/25.
//

#include "factories/StateManagerFactory.h"
#include "factories/DefaultStateFactory.h"
#include "states/menu/MenuState.h"
#include "states/IStateInputHandler.h"
#include "states/IStateUpdateHandler.h"

namespace renderer {
    std::unique_ptr<StateManager> StateManagerFactory::createStateManager(std::unique_ptr<IStateFactory> stateFactory) {
        auto menuState = stateFactory->createMenuState();
        return std::make_unique<StateManager>(std::move(menuState),std::move(stateFactory));
    }
} // renderer