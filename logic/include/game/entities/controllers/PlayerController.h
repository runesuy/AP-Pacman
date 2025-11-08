//
// Created by rune-suy on 11/7/25.
//

#ifndef AP_PACMAN_PLAYERCONTROLLER_H
#define AP_PACMAN_PLAYERCONTROLLER_H

#include "core/entity/IEntityController.h"
#include "game/entities/models/PlayerModel.h"
#include "core/world/TileMap.h"

namespace logic {

    class PlayerController : public IEntityController<PlayerModel> {
    public:
        void update(World& world, PlayerModel& entity) override;

        void processCommand(EntityCommand command, PlayerModel &entity) override;

    private:
        static TileMap::TileType getTileInDirection(const World& world, const PlayerModel& entity, PlayerModel::Direction direction) ;

        /**
         * Check if the player has passed the center of the current tile in the given direction.
         * @param world
         * @param entity
         * @param direction
         * @return True and the center position if past center, false otherwise.
         */
        static std::tuple<bool,Position> _isPastOrOnCenter(const logic::World &world, const logic::PlayerModel &entity, logic::PlayerModel::Direction direction) ;
    };

} // logic

#endif //AP_PACMAN_PLAYERCONTROLLER_H
