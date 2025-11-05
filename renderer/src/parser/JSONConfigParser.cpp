//
// Created by rune-suy on 11/5/25.
//

#include "parser/JSONConfigParser.h"
#include "exceptions/FileNotOpenedException.h"
#include <stdexcept>
#include <fstream>

namespace renderer {
    std::string JSONConfigParser::getDefaultFontPath() {
        if (_jsonData.empty()) {
            throw std::runtime_error("Configuration data not loaded.");
        }
        return _jsonData["fonts"]["defaultFont"].get<std::string>();
    }

    void JSONConfigParser::loadConfigFile() {
        std::ifstream inputFile(configFilePath);
        if (!inputFile.is_open()) {
            throw FileNotOpenedException(configFilePath);
        }

        try {
            inputFile >> _jsonData;
            inputFile.close();
        } catch (const json::parse_error &e) {
            inputFile.close();
            throw std::runtime_error("Error parsing JSON config file: " + std::string(e.what()));
        }
    }
} // renderer