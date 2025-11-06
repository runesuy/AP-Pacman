//
// Created by rune-suy on 11/6/25.
//

#include <fstream>
#include "parser/TXTMapParser.h"
#include "exceptions/FileNotOpenedException.h"

namespace renderer {
    logic::TileMap TXTMapParser::loadMap(const std::string &filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) throw FileNotOpenedException(filename);

        logic::TileMap tileMap;
        int width = -1;
        std::string line;
        while (std::getline(inputFile, line)) {
            if (width == -1) {
                width = static_cast<int>(line.length());
            } else if (static_cast<int>(line.length()) != width) {
                throw std::runtime_error("Inconsistent line lengths in map file: " + filename);
            }

            std::vector<logic::TileMap::TileType> row;
            for (char ch : line) {
                switch (ch) {
                    case EMPTY_CHAR:
                        row.push_back(logic::TileMap::EMPTY);
                        break;
                    case WALL_CHAR:
                        row.push_back(logic::TileMap::WALL);
                        break;
                    case COIN_CHAR:
                        row.push_back(logic::TileMap::COIN);
                        break;
                    case POWER_UP_CHAR:
                        row.push_back(logic::TileMap::POWER_UP);
                        break;
                    case SPAWN_CHAR:
                        row.push_back(logic::TileMap::SPAWN);
                        break;
                    case GHOST_CHAR:
                        row.push_back(logic::TileMap::GHOST);
                        break;
                    case PLAYER_CHAR:
                        row.push_back(logic::TileMap::PLAYER);
                        break;
                    default:
                        throw std::runtime_error("Invalid character in map file: " + std::string(1, ch));
                }
            }
            tileMap.addRow(row);
        }

        return tileMap;
    }
} // renderer