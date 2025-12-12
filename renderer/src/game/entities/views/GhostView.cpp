//
// Created by runes on 21/11/2025.
//

#include "game/entities/views/GhostView.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void GhostView::updateAnimation() {
        std::string animExt = "";
        getModule<AnimatedSpriteModule>()->setFrameDuration(FRAME_DURATION);
        if (ghostMode == logic::GhostModel::FRIGHTENED) {
            animExt = "-frightened";
            if (frightenedTimer > FRIGHTENED_END_ANIM_START) {
                animExt += "-end";
                getModule<AnimatedSpriteModule>()->setFrameDuration(FRAME_DURATION * 2);
            }
        }
        if (ghostMode == logic::GhostModel::RETURNING_HOME) {
            animExt = "-returning";
        }

        switch (direction) {
            case logic::Direction::RIGHT: {
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-right" + animExt);
                }
                break;
            }
            case (logic::Direction::LEFT): {
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-left" + animExt);
                }
                break;
            }
            case (logic::Direction::UP): {
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-up" + animExt);
                }
                break;
            }
            case (logic::Direction::DOWN): {
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-down" + animExt);
                }
                break;
            }
            case logic::NONE:
                break;
        }
    }

    void GhostView::update(logic::GhostModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        setDirection(subject.getDirection());
        setGhostMode(subject.getMode());
        setFrightenedTimer(subject.getFrightenedTimer());
        updateAnimation();
    }

    bool GhostView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void GhostView::markForRemoval() {
        markedForRemoval = true;
    }

    GhostView::GhostView(const GhostView::AnimationsMap &animationsMap) {
        auto animatedSpriteModule = std::make_shared<AnimatedSpriteModule>();
        animatedSpriteModule->setSize(getSize());
        animatedSpriteModule->setAnimations(animationsMap);
        animatedSpriteModule->setCurrentAnimation("move-right");
        animatedSpriteModule->setFrameDuration(FRAME_DURATION);
        addModule(animatedSpriteModule);
        addObserver(animatedSpriteModule);
    }

    void GhostView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    void GhostView::setDirection(logic::Direction direction) {
        this->direction = direction;
    }

    logic::GhostModel::Mode GhostView::getGhostMode() const {
        return ghostMode;
    }

    void GhostView::setGhostMode(logic::GhostModel::Mode ghostMode) {
        GhostView::ghostMode = ghostMode;
    }

    void GhostView::setFrightenedTimer(float frightenedTimer) {
        GhostView::frightenedTimer = frightenedTimer;
    }
} // renderer