//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_IENTITYCOMMAND_H
#define AP_PACMAN_IENTITYCOMMAND_H

namespace logic
{
    /**
     * Commands that can be passed to the entities.
     * These commands can be used in the entityControllers.
     *
     * @see IEntityController::processCommand(...)
     */
    enum EntityCommand
    {
        TURN_LEFT,
        TURN_RIGHT,
        TURN_UP,
        TURN_DOWN,
    };
}


#endif //AP_PACMAN_IENTITYCOMMAND_H
