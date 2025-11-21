//
// Created by runes on 21/11/2025.
//

#ifndef AP_PACMAN_GHOSTVIEW_H
#define AP_PACMAN_GHOSTVIEW_H

#include "core/entity/modular/ModularEntityView.h"
#include "game/entities/models/GhostModel.h"
#include "core/entity/modular/modules/AnimatedSpriteModule.h"

namespace renderer {

    class GhostView : public ModularEntityView, public logic::IObserver<logic::GhostModel>{
        bool markedForRemoval{false};
        logic::Direction direction = logic::NONE;
        logic::GhostModel::Mode ghostMode=logic::GhostModel::WAITING;

        void updateAnimation();

    public:
        using AnimationsMap = AnimatedSpriteModule::AnimationNamesMap;
        explicit GhostView(const AnimationsMap& animationsMap);

        void update(logic::GhostModel &subject) override;

        bool isMarkedForRemoval() override;

        void markForRemoval();

        void setSize(const logic::Size &size) override;

        void setDirection(logic::Direction direction);

        [[nodiscard]] logic::GhostModel::Mode getGhostMode() const;

        void setGhostMode(logic::GhostModel::Mode ghostMode);
    };

} // renderer

#endif //AP_PACMAN_GHOSTVIEW_H
