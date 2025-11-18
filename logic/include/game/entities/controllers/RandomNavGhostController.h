//
// Created by rune-suy on 11/12/25.
//

#ifndef AP_PACMAN_RANDOMNAVGHOSTCONTROLLER_H
#define AP_PACMAN_RANDOMNAVGHOSTCONTROLLER_H
#include "MovingEntityController.h"
#include "game/entities/models/GhostModel.h"
#include "GhostController.h"

namespace logic {
    class RandomNavGhostController : public GhostController{
    public:
        void processCommand(EntityCommand command, GhostModel &entity) override;

        void onCollision(GhostModel &entity, const SizedWorldObject &other) override;

        void update(World &world, GhostModel &entity) override;

        void onWallCollision(logic::World &world, logic::GhostModel &entity) override;

        void onIsStationary(logic::World &world, logic::GhostModel &entity);

        std::vector<Direction> getViableDirections(const World &world, const GhostModel &entity);
    };

}
#endif //AP_PACMAN_RANDOMNAVGHOSTCONTROLLER_H
