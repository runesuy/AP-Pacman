//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_JSONCONFIGPARSER_H
#define AP_PACMAN_JSONCONFIGPARSER_H

#include "IConfigParser.h"
#include "json.hpp"

namespace renderer {
    using json = nlohmann::json;

    /**
     * Concrete implementation of IConfigParser that reads configuration from a JSON file.
     * Reads file resources/config.json
     */
    class JSONConfigParser : public IConfigParser {
        json _jsonData;
        const std::string configFilePath = "resources/config.json";
    public:
        std::string getDefaultFontPath() override;

        void loadConfigFile() override;
    };

} // renderer

#endif //AP_PACMAN_JSONCONFIGPARSER_H
