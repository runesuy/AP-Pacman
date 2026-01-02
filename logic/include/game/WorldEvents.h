//
// Created by runes on 20/11/2025.
//

#ifndef AP_PACMAN_WORLDEVENTS_H
#define AP_PACMAN_WORLDEVENTS_H


namespace logic
{
    struct WorldEvents
    {
        enum WorldEvent
        {
            FRUIT_EATEN_BY_PLAYER,
            PLAYER_KILLED,
            PLAYER_GHOST_KILLED,
            COIN_COLLECTED
        };
    };
}

#endif //AP_PACMAN_WORLDEVENTS_H
