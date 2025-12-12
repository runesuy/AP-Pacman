//
// Created by rune-suy on 11/13/25.
//

#ifndef AP_PACMAN_ANIMATEDSPRITEMODULE_H
#define AP_PACMAN_ANIMATEDSPRITEMODULE_H


#include "core/entity/modular/IEntityViewModule.h"
#include "core/world/space/Size.h"
#include "core/parser/ITextureParser.h"

namespace renderer {
    /**
     * Entity view module for rendering animated sprites.
     */
    class AnimatedSpriteModule : public IEntityViewModule {
        std::map<std::string, std::vector<std::shared_ptr<sf::Texture> > > textures;
        std::string currentAnimation;
        float frameDuration = 0.1f;
        logic::Size size = {0.1, 0.1};

        mutable float elapsedTime = 0.0f;
        mutable int currentFrameIndex = 0;
        mutable sf::Sprite sprite;

    public:
        using AnimationNamesMap = std::map<std::string, std::vector<std::string> >;

        AnimatedSpriteModule() = default;

        void update(ModularEntityView &subject) override;

        std::vector<std::unique_ptr<sf::Shape> > getSFShapes(sf::RenderWindow &window) const override;

        std::vector<std::shared_ptr<sf::Sprite> > getSFSprites(sf::RenderWindow &window) const override;

        [[nodiscard]] std::vector<std::unique_ptr<sf::Text> > getSFTexts() const override;

        /**
         * Set the animations map.
         * The animations map maps animation names to a vector of textures representing the frames of the animation.
         * @param textures
         */
        void setAnimations(const std::map<std::string, std::vector<std::shared_ptr<sf::Texture> > > &textures);

        /**
         * Set the animations map using a AnimationNamesMap.
         * The animations map maps animation names to a vector of textures representing the frames of the animation.
         * The AnimationNamesMap maps animation names to a vector of texture names.
         * The texture names need to be present in config.json.
         * @param textures
         */
        void setAnimations(const AnimationNamesMap &textures);

        /**
         * Set the size of the animated sprite.
         * @param size
         */
        void setSize(const logic::Size &size);

        /**
         * Set the frame duration of the animated sprite.
         * @param frameDuration Frame duration in seconds.
         */
        void setFrameDuration(float frameDuration);

        /**
         * Set the current animation by name.
         * The name needs to be present in the animations map.
         * @param currentAnimation
         */
        void setCurrentAnimation(const std::string &currentAnimation);
    };
} // renderer

#endif //AP_PACMAN_ANIMATEDSPRITEMODULE_H
