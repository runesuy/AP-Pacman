//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_LEVELDRAWHANDLER_H
#define AP_PACMAN_LEVELDRAWHANDLER_H

#include "core/states/IStateDrawHandler.h"
#include "core/states/IState.h"
#include "LevelState.h"

namespace renderer {

    /**
     * Draw handler for the LevelState, responsible for rendering the game level and its entities.
     */
class LevelDrawHandler : public IStateDrawHandler<LevelState>{
    public:
    void draw(sf::RenderWindow &window, LevelState &state, StateManager& stateManager) override;
};

} // renderer

#endif //AP_PACMAN_LEVELDRAWHANDLER_H
