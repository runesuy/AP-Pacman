//
// Created by runes on 27/11/2025.
//

#ifndef AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
#define AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
#include "core/states/IStateDrawHandler.h"
#include "core/drawable/ui/Label.h"

namespace renderer {

    class PausedStateDrawHandler : public IStateDrawHandler{
        Label pausedLabel;
        inline static const std::string pausedLabelText = "PAUSED";
        inline static const float pausedLabelCharSize = 0.1;
        Label descrLabel;
        inline static const std::string descrLabelText = "PRESS ANY KEY TO CONTINUE";
        inline static const float descrLabelCharSize = 0.05;
    public:
        PausedStateDrawHandler();
        void draw(sf::RenderWindow &window, IState &state) override;
    };

} // renderer

#endif //AP_PACMAN_PAUSEDSTATEDRAWHANDLER_H
