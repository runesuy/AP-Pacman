//
// Created by rune-suy on 11/5/25.
//

#include "game/states/level/LevelUpdateHandler.h"
#include "game/states/level/LevelState.h"

namespace renderer {

    void LevelUpdateHandler::update(IState &state) {
        try {
            auto &levelState = dynamic_cast<LevelState &>(state);
            levelState.getWorld()->update();
        }
        catch (const std::bad_cast &e) {
            throw std::runtime_error("LevelUpdateHandler can only update LevelState");
        }
    }
} // renderer