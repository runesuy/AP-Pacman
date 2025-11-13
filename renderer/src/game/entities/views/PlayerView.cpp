//
// Created by rune-suy on 11/7/25.
//

#include "game/entities/views/PlayerView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void PlayerView::update(logic::PlayerModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        setDirection(subject.getDirection());
        _updateAnimation();
    }

    PlayerView::PlayerView() {
        auto animatedSpriteModule = std::make_shared<AnimatedSpriteModule>();
        animatedSpriteModule->setSize(getSize());
        animatedSpriteModule->setAnimations(animations);
        animatedSpriteModule->setCurrentAnimation("none");
        animatedSpriteModule->setFrameDuration(0.2f);
        addModule(animatedSpriteModule);
        addObserver(animatedSpriteModule);
    }

    void PlayerView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    bool PlayerView::isMarkedForRemoval() {
        return false;
    }

    void PlayerView::_updateAnimation() {
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
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("none");
                }
                break;
        }
    }

    void PlayerView::setDirection(logic::Direction direction) {
        PlayerView::direction = direction;
    }

} // renderer