//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_IMAPPARSER_H
#define AP_PACMAN_IMAPPARSER_H
#include <string>
#include "core/world/TileMap.h"

namespace renderer
{
    /**
     * Interface for map parser, responsible for loading tile maps from files.
     */
    class IMapParser
    {
    public:
        virtual ~IMapParser() = default;

        /**
         * Read a tile map from the specified file.
         * @param filename
         * @return
         */
        virtual logic::TileMap loadMap(const std::string& filename) = 0;
    };
} // renderer

#endif //AP_PACMAN_IMAPPARSER_H
