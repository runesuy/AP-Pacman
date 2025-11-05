//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELINPUTHANDLER_H
#define AP_PACMAN_LEVELINPUTHANDLER_H

#include "core/IInputHandler.h"
#include "states/IStateInputHandler.h"

namespace renderer {

    class LevelInputHandler : public IStateInputHandler {
    public:
        void processInput(sf::Event &event, StateManager& stateManager) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELINPUTHANDLER_H
