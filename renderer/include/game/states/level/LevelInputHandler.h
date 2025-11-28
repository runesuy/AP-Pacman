//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELINPUTHANDLER_H
#define AP_PACMAN_LEVELINPUTHANDLER_H

#include "core/states/IStateInputHandler.h"
#include "LevelState.h"

namespace renderer {
    class IState;

    /**
     * Input handler for the LevelState, processing user inputs during gameplay and passing it to logic.
     */
    class LevelInputHandler : public IStateInputHandler<LevelState> {
    public:
        void processInput(sf::Event &event, StateManager& stateManager, LevelState& state, const sf::RenderWindow& window) override;
    };

} // renderer

#endif //AP_PACMAN_LEVELINPUTHANDLER_H
