//
// Created by rune-suy on 11/5/25.
//

#include "parser/JSONConfigParser.h"
#include "exceptions/FileNotOpenedException.h"
#include <stdexcept>
#include <fstream>

namespace renderer {
    std::string JSONConfigParser::getDefaultFontPath() {
        if (!_jsonData) {
            throw std::runtime_error("Configuration data not loaded.");
        }
        return _jsonData["defaultFont"];
    }

    void JSONConfigParser::loadConfigFile() {
        std::ifstream inputFile(configFilePath);
        if (!inputFile.is_open()) {
            throw FileNotOpenedException(configFilePath);
        }

        try {
            inputFile >> _jsonData;
        } catch (const json::parse_error &e) {
            throw std::runtime_error("Error parsing JSON config file: " + std::string(e.what()));
        }
    }
} // renderer