//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_TXTMAPPARSER_H
#define AP_PACMAN_TXTMAPPARSER_H

#include "core/parser/IMapParser.h"

namespace renderer {

    /**
     * Concrete implementation of IMapParser that reads tile maps from TXT files.
     */
    class TXTMapParser : public IMapParser {
    public:
        static const char WALL_CHAR = 'W';
        static const char COIN_CHAR = '.';
        static const char PLAYER_CHAR = 'P';
        static const char GHOST_CHAR = 'G';
        static const char SPAWN_CHAR = 'S';
        static const char EMPTY_CHAR = ' ';
        static const char POWER_UP_CHAR = 'U';

        logic::TileMap loadMap(const std::string &filename) override;
    };

} // renderer

#endif //AP_PACMAN_TXTMAPPARSER_H
