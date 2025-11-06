//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DEFAULTLOGICCONFIG_H
#define AP_PACMAN_DEFAULTLOGICCONFIG_H

#include "IConfig.h"

namespace renderer {

    class DefaultLogicConfig : public logic::IConfig {
    public:
        [[nodiscard]] logic::TileMap getTileMap() const override;

        [[nodiscard]] std::unique_ptr<logic::IEntityFactory> getEntityFactory() const override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTLOGICCONFIG_H
