//
// Created by rune-suy on 11/6/25.
//

#include "game/configs/DefaultLogicConfig.h"
#include "game/parsers/TXTMapParser.h"
#include "game/factories/DefaultEntityFactory.h"

namespace renderer {
    logic::TileMap DefaultLogicConfig::getTileMap() const {
        TXTMapParser parser;
        return parser.loadMap("resources/maps/map1.txt");
    }

    std::unique_ptr<logic::IEntityFactory> DefaultLogicConfig::getEntityFactory() const {
        return std::make_unique<DefaultEntityFactory>();
    }
} // renderer