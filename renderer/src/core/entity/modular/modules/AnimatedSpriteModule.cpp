//
// Created by rune-suy on 11/13/25.
//

#include <iostream>
#include "core/entity/modular/modules/AnimatedSpriteModule.h"
#include "core/utils/Stopwatch.h"
#include "core/utils/Camera.h"
#include "core/entity/modular/ModularEntityView.h"
#include "game/Game.h"

namespace renderer {
    void AnimatedSpriteModule::update(ModularEntityView &subject) {
        setSize(subject.getSize());
    }

    std::vector<std::unique_ptr<sf::Shape>> AnimatedSpriteModule::getSFShapes(sf::RenderWindow &window) const {
        return {};
    }

    std::vector<std::shared_ptr<sf::Sprite>> AnimatedSpriteModule::getSFSprites(sf::RenderWindow &window) const {
        if (!textures.contains(currentAnimation) || textures.at(currentAnimation).empty()) {
            return {};
        }

        elapsedTime += logic::Stopwatch::getInstance()->getDeltaTime();

        while (elapsedTime >= frameDuration) {
            elapsedTime -= frameDuration;
            currentFrameIndex = (currentFrameIndex + 1) % static_cast<int>(textures.at(currentAnimation).size());
        }

        sprite.setTexture(*textures.at(currentAnimation).at(currentFrameIndex));
        sf::Vector2<unsigned int> textureSize = textures.at(currentAnimation).at(currentFrameIndex)->getSize();
        sf::Vector2<float> projectedSize = Camera::project(size, window);
        sprite.setScale(projectedSize.x / static_cast<float>(textureSize.x),
                        projectedSize.y / static_cast<float>(textureSize.y));
        sprite.setOrigin(static_cast<float>(textureSize.x) / 2.0f, static_cast<float>(textureSize.y) / 2.0f);
        return {std::make_shared<sf::Sprite>(sprite)};

    }

    std::vector<std::unique_ptr<sf::Text>> AnimatedSpriteModule::getSFTexts() const {
        return {};
    }

    void AnimatedSpriteModule::setAnimations(
            const std::map<std::string, std::vector<std::shared_ptr<sf::Texture>>> &textures) {
        this->textures = textures;
    }

    void AnimatedSpriteModule::setSize(const logic::Size &size) {
        this->size = size;
    }

    void AnimatedSpriteModule::setFrameDuration(float frameDuration) {
        AnimatedSpriteModule::frameDuration = frameDuration;
    }

    void AnimatedSpriteModule::setCurrentAnimation(const std::string &currentAnimation) {
        AnimatedSpriteModule::currentAnimation = currentAnimation;
    }

    void AnimatedSpriteModule::setAnimations(const std::map<std::string, std::vector<std::string>> &textures) {
        this->textures.clear();
        for (auto &[animationName, textureVec]: textures) {
            for (const std::string &textureName: textureVec) {
                this->textures[animationName].push_back(std::make_shared<sf::Texture>(
                        Game::getInstance()->getAppConfig().getTextureParser().getTexture(textureName)));
            }
        }
    }


} // renderer