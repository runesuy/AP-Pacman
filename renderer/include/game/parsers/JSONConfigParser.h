//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_JSONCONFIGPARSER_H
#define AP_PACMAN_JSONCONFIGPARSER_H

#include <SFML/Graphics/Rect.hpp>
#include "core/parser/IConfigParser.h"
#include "json.hpp"

namespace renderer
{
    using json = nlohmann::json;

    /**
     * Concrete implementation of IConfigParser that reads configuration from a JSON file.
     * Reads file resources/config.json
     */
    class JSONConfigParser : public IConfigParser
    {
        json _jsonData;
        const std::string configFilePath = "resources/config.json";

    public:
        [[nodiscard]] std::string getDefaultFontPath() const override;

        void loadConfigFile() override;

        [[nodiscard]] std::string getSpriteSheetPath() const override;

        [[nodiscard]] std::map<std::string, sf::IntRect> getTextureRects() const override;

        [[nodiscard]] sf::IntRect getTextureRectByName(const std::string& name) const override;
    };
} // renderer

#endif //AP_PACMAN_JSONCONFIGPARSER_H
