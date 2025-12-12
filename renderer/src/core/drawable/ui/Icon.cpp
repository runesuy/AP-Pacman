//
// Created by runes on 21/11/2025.
//

#include "core/drawable/ui/Icon.h"
#include "core/utils/Camera.h"

namespace renderer {
    std::vector<std::unique_ptr<sf::Shape> > Icon::getSFShapes(sf::RenderWindow &window) {
        return {};
    }

    std::vector<std::shared_ptr<sf::Sprite> > Icon::getSFSprites(sf::RenderWindow &window) {
        std::vector<std::shared_ptr<sf::Sprite> > sprites;
        sf::Vector2<unsigned int> textureSize = sprite.getTexture()->getSize();
        sf::Vector2<float> projectedSize = Camera::project(size, window);
        sprite.setScale(projectedSize.x / static_cast<float>(textureSize.x),
                        projectedSize.y / static_cast<float>(textureSize.y));
        sprite.setOrigin(static_cast<float>(textureSize.x) / 2.0f, static_cast<float>(textureSize.y) / 2.0f);
        return {std::make_shared<sf::Sprite>(sprite)};
    }

    std::vector<std::unique_ptr<sf::Text> > Icon::getSFTexts(sf::RenderWindow &window) {
        return {};
    }

    void Icon::setTexture(const sf::Texture &texture) {
        sprite.setTexture(texture);
    }

    void Icon::setSize(const logic::Size &size) {
        this->size = size;
    }
} // renderer