//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_IMAPPARSER_H
#define AP_PACMAN_IMAPPARSER_H
#include <string>
#include "world/TileMap.h"

namespace renderer {

    class IMapParser {
    public:
        virtual logic::TileMap loadMap(const std::string& filename) = 0;
    };

} // renderer

#endif //AP_PACMAN_IMAPPARSER_H
