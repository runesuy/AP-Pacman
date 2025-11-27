//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
#define AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
#include "core/states/IStateInputHandler.h"
#include "PausedState.h"

namespace renderer {

    class PausedStateInputHandler : public IStateInputHandler<PausedState>{
    public:
        void processInput(sf::Event &event, StateManager &stateManager, PausedState &state) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
