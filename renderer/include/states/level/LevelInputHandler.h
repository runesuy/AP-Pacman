//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELINPUTHANDLER_H
#define AP_PACMAN_LEVELINPUTHANDLER_H

#include "states/IStateInputHandler.h"

namespace renderer {
    class IState;

    /**
     * Input handler for the LevelState, processing user inputs during gameplay and passing it to logic.
     */
    class LevelInputHandler : public IStateInputHandler {
    public:
        void processInput(sf::Event &event, StateManager& stateManager, IState& state) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELINPUTHANDLER_H
