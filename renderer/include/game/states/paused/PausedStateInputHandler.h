//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
#define AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
#include "core/states/IStateInputHandler.h"

namespace renderer {

    class PausedStateInputHandler : public IStateInputHandler{
    public:
        void processInput(sf::Event &event, StateManager &stateManager, IState &state) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEINPUTHANDLER_H
