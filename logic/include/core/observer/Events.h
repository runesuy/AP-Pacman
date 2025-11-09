//
// Created by rune-suy on 11/9/25.
//

#ifndef AP_PACMAN_EVENTS_H
#define AP_PACMAN_EVENTS_H

#endif //AP_PACMAN_EVENTS_H

namespace logic {
    enum GameEventType {
        ENTITY_SPAWNED,
        ENTITY_REMOVED,
        ENTITY_MOVED,
        ENTITY_SIZE_CHANGED,
        COIN_COLLECTED,
        POWERUP_COLLECTED,
        GHOST_KILLED,
        PLAYER_DIED
    };
}

