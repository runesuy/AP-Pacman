//
// Created by rune-suy on 11/13/25.
//

#include "game/entities/views/BlueGhostView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void BlueGhostView::update(logic::GhostModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        setDirection(subject.getDirection());
        updateAnimation();
    }

    bool BlueGhostView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void BlueGhostView::markForRemoval() {
        markedForRemoval = true;
    }

    void BlueGhostView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    BlueGhostView::BlueGhostView() {
        auto animatedSpriteModule = std::make_shared<AnimatedSpriteModule>();
        animatedSpriteModule->setSize(getSize());
        animatedSpriteModule->setAnimations(animations);
        animatedSpriteModule->setCurrentAnimation("move-right");
        animatedSpriteModule->setFrameDuration(0.2f);
        addModule(animatedSpriteModule);
        addObserver(animatedSpriteModule);
    }

    void BlueGhostView::updateAnimation() {
        switch (direction) {
            case logic::Direction::RIGHT :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-right");
                }
                break;
            }
            case (logic::Direction::LEFT) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-left");
                }
                break;
            }
            case (logic::Direction::UP) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-up");
                }
                break;
            }
            case (logic::Direction::DOWN) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-down");
                }
                break;
            }
            case logic::NONE:
                break;
        }
    }

    void BlueGhostView::setDirection(logic::Direction direction) {
        this->direction = direction;
    }
} // renderer