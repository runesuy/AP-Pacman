//
// Created by rune-suy on 11/6/25.
//

#include "core/entity/modular/modules/SpriteModule.h"
#include "core/entity/modular/ModularEntityView.h"
#include "core/utils/Camera.h"

namespace renderer
{
    void SpriteModule::update(ModularEntityView& subject)
    {
        setSize(subject.getSize());
    }

    std::vector<std::unique_ptr<sf::Shape>> SpriteModule::getSFShapes(sf::RenderWindow& window) const
    {
        return {};
    }

    std::vector<std::shared_ptr<sf::Sprite>> SpriteModule::getSFSprites(sf::RenderWindow& window) const
    {
        std::vector<std::shared_ptr<sf::Sprite>> sprites;
        sf::Vector2<unsigned int> textureSize = sprite.getTexture()->getSize();
        sf::Vector2<float> projectedSize = Camera::project(size, window);
        sprite.setScale(projectedSize.x / static_cast<float>(textureSize.x),
                        projectedSize.y / static_cast<float>(textureSize.y));
        sprite.setOrigin(static_cast<float>(textureSize.x) / 2.0f, static_cast<float>(textureSize.y) / 2.0f);
        return {std::make_shared<sf::Sprite>(sprite)};
    }

    std::vector<std::unique_ptr<sf::Text>> SpriteModule::getSFTexts() const
    {
        return {};
    }

    void SpriteModule::setSize(const logic::Size& size)
    {
        SpriteModule::size = size;
    }

    void SpriteModule::setTexture(const sf::Texture& texture)
    {
        SpriteModule::sprite.setTexture(texture);
    }
} // renderer
