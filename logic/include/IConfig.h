//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ICONFIG_H
#define AP_PACMAN_ICONFIG_H

#include "world/TileMap.h"
#include "entity/IEntityFactory.h"

namespace logic {

    class IConfig {
    public:
        virtual ~IConfig() = default;

        [[nodiscard]] virtual TileMap getTileMap() const = 0;

        [[nodiscard]] virtual std::unique_ptr<IEntityFactory> getEntityFactory() const = 0;
    };

} // logic

#endif //AP_PACMAN_ICONFIG_H
