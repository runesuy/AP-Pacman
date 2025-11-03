//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_GAME_H
#define AP_PACMAN_GAME_H

namespace renderer {
    /**
         * Manages the representation side of the game, such as:
         * - Game loop
         * - Factory creation
         * - Processing user interaction
         */
    class Game {
    public:
        /**
         * Start the game.
         */
        void run();
    };
}


#endif //AP_PACMAN_GAME_H
