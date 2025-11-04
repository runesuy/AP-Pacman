//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ISTATE_H
#define AP_PACMAN_ISTATE_H


namespace renderer {
    class IState {
        virtual void update()=0;
    };
}


#endif //AP_PACMAN_ISTATE_H
