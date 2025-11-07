//
// Created by rune-suy on 11/6/25.
//

#include "core/entity/modular/modules/SpriteModule.h"
#include "core/entity/modular/ModularEntityView.h"

namespace renderer {
    void SpriteModule::update(std::shared_ptr<ModularEntityView> subject) {
        setSize(subject->getSize());
    }

    std::vector<std::unique_ptr<sf::Shape>> SpriteModule::getSFShapes(sf::RenderWindow &window) const {
        return {};
    }

    std::vector<std::shared_ptr<sf::Sprite>> SpriteModule::getSFSprites() const {
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        return {std::make_shared<sf::Sprite>(sprite)};
    }

    std::vector<std::unique_ptr<sf::Text>> SpriteModule::getSFTexts() const {
        return {};
    }

    void SpriteModule::setSize(const logic::Size &size) {
        SpriteModule::size = size;
    }

    void SpriteModule::setTexture(const sf::Texture &texture) {
        SpriteModule::sprite.setTexture(texture);
    }
} // renderer