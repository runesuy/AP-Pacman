//
// Created by runes on 21/11/2025.
//

#ifndef AP_PACMAN_ICON_H
#define AP_PACMAN_ICON_H

#include "core/drawable/DrawObject.h"
#include "core/world/space/Size.h"

namespace renderer
{
    class Icon : public DrawObject
    {
        sf::Sprite sprite;
        logic::Size size = {0.1, 0.1};

    public:
        Icon() = default;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow& window) override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow& window) override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts(sf::RenderWindow& window) override;

        /**
         * Sets the texture of the icon.
         * @param texture
         */
        void setTexture(const sf::Texture& texture);

        void setSize(const logic::Size& size);
    };
} // renderer

#endif //AP_PACMAN_ICON_H
