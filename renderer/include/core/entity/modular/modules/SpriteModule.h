//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_SPRITEMODULE_H
#define AP_PACMAN_SPRITEMODULE_H

#include "core/entity/modular/IEntityViewModule.h"
#include "world/Size.h"

namespace renderer {

    class SpriteModule : public IEntityViewModule {
        logic::Size size={0.1,0.1};
        sf::Sprite sprite;
    public:
        SpriteModule()=default;

        void update(std::shared_ptr<ModularEntityView> subject) override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) const override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites() const override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts() const override;

        void setTexture(const sf::Texture &texture);

        void setSize(const logic::Size &size);
    };

} // renderer

#endif //AP_PACMAN_SPRITEMODULE_H
