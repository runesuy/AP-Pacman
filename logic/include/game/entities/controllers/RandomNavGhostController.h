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

        /**
         * Choose a direction to request based on the viable options.
         * Entity has a 50% chance of changing directions, otherwise entity will continue on its current path.
         * Entity will only turn 180 degrees in one time if this is the only option.
         * @param world
         * @param entity
         */
        static void chooseDirection(logic::World &world, logic::GhostModel &entity);

        static std::vector<Direction> getViableDirections(const World &world, const GhostModel &entity);
    };

}
#endif //AP_PACMAN_RANDOMNAVGHOSTCONTROLLER_H
