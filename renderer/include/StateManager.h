//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_STATEMANAGER_H
#define AP_PACMAN_STATEMANAGER_H
#include "stack"
#include "IState.h"
#include "memory"
#include "MenuState.h"

namespace renderer {
    class StateManager {
        std::stack<std::unique_ptr<IState>> stack;
    public:
        explicit StateManager(std::unique_ptr<IState> &&initialState);
    };
}


#endif //AP_PACMAN_STATEMANAGER_H
