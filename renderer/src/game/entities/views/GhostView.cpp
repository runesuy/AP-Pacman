//
// Created by runes on 21/11/2025.
//

#include "game/entities/views/GhostView.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void GhostView::updateAnimation() {
        std::string animExt = "";
        if (ghostMode == logic::GhostModel::FRIGHTENED) animExt = "-frightened";
        switch (direction) {
            case logic::Direction::RIGHT :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-right" + animExt);
                }
                break;
            }
            case (logic::Direction::LEFT) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-left"+ animExt);
                }
                break;
            }
            case (logic::Direction::UP) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-up"+ animExt);
                }
                break;
            }
            case (logic::Direction::DOWN) :{
                auto module = getModule<AnimatedSpriteModule>();
                if (module) {
                    module->setCurrentAnimation("move-down"+ animExt);
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
        animatedSpriteModule->setFrameDuration(0.2f);
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
} // renderer