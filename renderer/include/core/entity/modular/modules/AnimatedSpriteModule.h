//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_ANIMATEDSPRITEMODULE_H
#define AP_PACMAN_ANIMATEDSPRITEMODULE_H


#include "core/entity/modular/IEntityViewModule.h"
#include "core/world/Size.h"

namespace renderer {

    class AnimatedSpriteModule : public IEntityViewModule{
        std::map<std::string,std::vector<std::shared_ptr<sf::Texture>>> textures;
        std::string currentAnimation;
        float frameDuration=0.1f;
        logic::Size size={0.1,0.1};

        mutable float elapsedTime=0.0f;
        mutable int currentFrameIndex=0;
        mutable sf::Sprite sprite;
    public:
        AnimatedSpriteModule()=default;

        void update(ModularEntityView &subject) override;

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) const override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow &window) const override;

        [[nodiscard]] std::vector<std::unique_ptr<sf::Text>> getSFTexts() const override;

        void setTextures(const std::map<std::string,std::vector<std::shared_ptr<sf::Texture>>> &textures);

        void setSize(const logic::Size &size);

        void setFrameDuration(float frameDuration);

        void setCurrentAnimation(const std::string &currentAnimation);
    };

} // renderer

#endif //AP_PACMAN_ANIMATEDSPRITEMODULE_H
