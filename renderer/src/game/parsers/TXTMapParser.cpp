//
// Created by rune-suy on 11/6/25.
//

#include <fstream>
#include "game/parsers/TXTMapParser.h"
#include "core/exceptions/FileNotOpenedException.h"

namespace renderer {
    logic::TileMap TXTMapParser::loadMap(const std::string &filename) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) throw logic::FileNotOpenedException(filename, "TXTMapParser::loadMap(const std::string &filename)");

        logic::TileMap tileMap;
        std::string::size_type width = -1;
        std::string line;
        while (std::getline(inputFile, line)) {
            if (width == -1) {
                width = line.length();
            } else if (line.length() != width) {
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
                    case GHOST_RED_CHAR:
                        row.push_back(logic::TileMap::GHOST_RED);
                        break;
                    case GHOST_PINK_CHAR:
                        row.push_back(logic::TileMap::GHOST_PINK);
                        break;
                    case GHOST_BLUE_CHAR:
                        row.push_back(logic::TileMap::GHOST_BLUE);
                        break;
                    case GHOST_ORANGE_CHAR:
                        row.push_back(logic::TileMap::GHOST_ORANGE);
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