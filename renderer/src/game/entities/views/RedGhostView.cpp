//
// Created by rune-suy on 11/13/25.
//

#include "game/entities/views/RedGhostView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void RedGhostView::update(logic::GhostModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
    }

    bool RedGhostView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void RedGhostView::markForRemoval() {
        markedForRemoval = true;
    }

    void RedGhostView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    RedGhostView::RedGhostView() {
        auto rectangleModule = std::make_shared<AnimatedSpriteModule>();
        rectangleModule->setSize(getSize());
        rectangleModule->setTextures({
            {"move-right",
             {
                    std::make_shared<sf::Texture>(Game::getInstance()->getAppConfig().getTextureParser().getTexture("ghost-red-right_0")),
                    std::make_shared<sf::Texture>(Game::getInstance()->getAppConfig().getTextureParser().getTexture("ghost-red-right_1"))
                }
            },
        });
        rectangleModule->setCurrentAnimation("move-right");
        rectangleModule->setFrameDuration(0.2f);
        addModule(rectangleModule);
        addObserver(rectangleModule);
    }
} // renderer