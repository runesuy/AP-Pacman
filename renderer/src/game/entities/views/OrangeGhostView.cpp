//
// Created by rune-suy on 11/13/25.
//

#include "game/entities/views/OrangeGhostView.h"
#include "core/entity/modular/modules/RectangleModule.h"
#include "core/entity/modular/modules/SpriteModule.h"
#include "game/Game.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {
    void OrangeGhostView::update(logic::GhostModel &subject) {
        setPosition(subject.getPosition());
        setSize(subject.getSize());
        setDirection(subject.getDirection());
        setGhostMode(subject.getMode());
        updateAnimation();
    }

    bool OrangeGhostView::isMarkedForRemoval() {
        return markedForRemoval;
    }

    void OrangeGhostView::markForRemoval() {
        markedForRemoval = true;
    }

    void OrangeGhostView::setSize(const logic::Size &size) {
        EntityView::setSize(size);
        updateObservers();
    }

    OrangeGhostView::OrangeGhostView() {
        auto animatedSpriteModule = std::make_shared<AnimatedSpriteModule>();
        animatedSpriteModule->setSize(getSize());
        animatedSpriteModule->setAnimations(animations);
        animatedSpriteModule->setCurrentAnimation("move-right");
        animatedSpriteModule->setFrameDuration(0.2f);
        addModule(animatedSpriteModule);
        addObserver(animatedSpriteModule);
    }

    void OrangeGhostView::updateAnimation() {
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

    void OrangeGhostView::setDirection(logic::Direction direction) {
        this->direction = direction;
    }

    logic::GhostModel::Mode OrangeGhostView::getGhostMode() const {
        return ghostMode;
    }

    void OrangeGhostView::setGhostMode(logic::GhostModel::Mode ghostMode) {
        OrangeGhostView::ghostMode = ghostMode;
    }
} // renderer