//
// Created by rune-suy on 11/6/25.
//

#include "game/configs/DefaultLogicConfig.h"
#include "game/parsers/TXTMapParser.h"
#include "game/factories/DefaultEntityFactory.h"
#include <filesystem>
#include "core/utils/Random.h"

namespace renderer {
    const logic::TileMap &DefaultLogicConfig::getTileMap() const {
        return tileMap;
    }

    void DefaultLogicConfig::loadTileMap() {
        TXTMapParser parser;
        const auto mapPaths = _getAllMapPaths();
        int randomI = logic::Random::getInstance()->getIntInRange(0, mapPaths.size() - 1);
        tileMap = parser.loadMap(mapPaths.at(randomI));
    }

    std::shared_ptr<logic::IEntityFactory> DefaultLogicConfig::getEntityFactory() const {
        return entityFactory;
    }

    std::vector<std::string> DefaultLogicConfig::_getAllMapPaths() const {
        std::vector<std::string> result;
        for (const auto &entry: std::filesystem::directory_iterator(_MapFolderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".txt") {
                result.push_back(entry.path().string());
            }
        }
        return result;
    }

    void DefaultLogicConfig::loadRandomMap() const {
    }
} // renderer
