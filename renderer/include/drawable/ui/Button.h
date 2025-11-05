//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_BUTTON_H
#define AP_PACMAN_BUTTON_H

#include "drawable/DrawObject.h"

namespace renderer {

    class Button : public DrawObject {
    public:
        void update() override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes() override;

        std::vector<std::unique_ptr<sf::Sprite>> getSFSprites() override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts() override;
    };

} // renderer

#endif //AP_PACMAN_BUTTON_H
