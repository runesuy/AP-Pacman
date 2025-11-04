//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_GAME_H
#define AP_PACMAN_GAME_H

#include <SFML/Window/Event.hpp>
#include "states/StateManager.h"
#include "world/World.h"
#include "IFactoryCollection.h"

namespace renderer {
    /**
     * Manages the representation side of the game, such as:
     * - Game loop
     * - Factory creation
     * - Processing user interaction
     */
    class Game {
        /**
         * The initial state the StateManager starts in
         */
        using InitialState = MenuState;

        bool running;

        IFactoryCollection& factoryCollection;
    public:
        explicit Game(IFactoryCollection& factoryCollection);

        /**
         * Start the game.
         */
        int run();
    };
}


#endif //AP_PACMAN_GAME_H
