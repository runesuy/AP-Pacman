//
// Created by rune-suy on 11/4/25.
//

#ifndef AP_PACMAN_STATEMANAGERFACTORY_H
#define AP_PACMAN_STATEMANAGERFACTORY_H

#include <memory>
#include "StateManager.h"

namespace renderer {

    class StateManagerFactory {
    public:
        [[maybe_unused]] [[maybe_unused]] std::unique_ptr<StateManager> createStateManager(std::unique_ptr<IStateFactory> stateFactory);
    };

} // renderer

#endif //AP_PACMAN_STATEMANAGERFACTORY_H
