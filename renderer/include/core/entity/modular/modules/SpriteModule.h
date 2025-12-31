//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_SPRITEMODULE_H
#define AP_PACMAN_SPRITEMODULE_H

#include "core/entity/modular/IEntityViewModule.h"
#include "core/world/space/Size.h"

namespace renderer
{
    /**
     * Entity module for rendering a non-animated sprite.
     */
    class SpriteModule : public IEntityViewModule
    {
        logic::Size size = {0.1, 0.1};
        mutable sf::Sprite sprite;

    public:
        /**
         * Size defaults to (0.1, 0.1)
         */
        SpriteModule() = default;

        void update(ModularEntityView& subject) override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow& window) const override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow& window) const override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts() const override;

        /**
         * Set the texture used by this sprite module.
         * @param texture Texture name available using the provided texture parser.
         */
        void setTexture(const sf::Texture& texture);

        void setSize(const logic::Size& size);
    };
} // renderer

#endif //AP_PACMAN_SPRITEMODULE_H
