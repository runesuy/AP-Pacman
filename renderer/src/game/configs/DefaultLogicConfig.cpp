//
// Created by rune-suy on 11/6/25.
//

#include "game/configs/DefaultLogicConfig.h"
#include "game/parsers/TXTMapParser.h"
#include "game/factories/DefaultEntityFactory.h"
#include <filesystem>

namespace renderer
{
    const logic::TileMap& DefaultLogicConfig::getTileMap() const
    {
        return tileMap;
    }

    void DefaultLogicConfig::loadTileMap()
    {
        TXTMapParser parser;
        tileMap = parser.loadMap(DEFAULT_MAP_PATH);
    }

    std::shared_ptr<logic::IEntityFactory> DefaultLogicConfig::getEntityFactory() const
    {
        return entityFactory;
    }

} // renderer
