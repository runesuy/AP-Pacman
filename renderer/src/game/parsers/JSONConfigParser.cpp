//
// Created by rune-suy on 11/5/25.
//

#include "game/parsers/JSONConfigParser.h"
#include "core/exceptions/FileNotOpenedException.h"
#include <stdexcept>
#include <fstream>

namespace renderer
{
    std::string JSONConfigParser::getDefaultFontPath() const
    {
        if (_jsonData.empty())
        {
            throw std::runtime_error("Configuration data not loaded.");
        }
        return _jsonData["fonts"]["defaultFont"].get<std::string>();
    }

    void JSONConfigParser::loadConfigFile()
    {
        std::ifstream inputFile(configFilePath);
        if (!inputFile.is_open())
        {
            throw logic::FileNotOpenedException(configFilePath, "JSONConfigParser::loadConfigFile()");
        }

        try
        {
            inputFile >> _jsonData;
            inputFile.close();
        }
        catch (const json::parse_error& e)
        {
            inputFile.close();
            throw std::runtime_error("Error parsing JSON config file: " + std::string(e.what()));
        }
    }

    std::string JSONConfigParser::getSpriteSheetPath() const
    {
        if (_jsonData.empty())
        {
            throw std::runtime_error("Configuration data not loaded.");
        }
        return _jsonData["spriteFile"].get<std::string>();
    }

    std::map<std::string, sf::IntRect> JSONConfigParser::getTextureRects() const
    {
        std::map<std::string, sf::IntRect> spriteMap;
        if (_jsonData.empty())
        {
            throw std::runtime_error("Configuration data not loaded.");
        }
        try
        {
            for (const auto& item : _jsonData["sprites"].items())
            {
                const std::string& key = item.key();
                const auto& value = item.value();
                sf::IntRect rect(
                    value["x"].get<int>(),
                    value["y"].get<int>(),
                    value["width"].get<int>(),
                    value["height"].get<int>()
                );
                spriteMap[key] = rect;
            }
            return spriteMap;
        }
        catch (const json::type_error& e)
        {
            throw std::runtime_error("Error parsing sprite paths from JSON config: " + std::string(e.what()));
        }
    }

    sf::IntRect JSONConfigParser::getTextureRectByName(const std::string& name) const
    {
        if (_jsonData.empty())
        {
            throw std::runtime_error("Configuration data not loaded.");
        }
        try
        {
            const auto& value = _jsonData["sprites"][name];
            return {
                value["x"].get<int>(),
                value["y"].get<int>(),
                value["width"].get<int>(),
                value["height"].get<int>()
            };
        }
        catch (const json::type_error& e)
        {
            throw std::runtime_error("Error retrieving texture rect for " + name + ": " + std::string(e.what()));
        }
    }
} // renderer
