//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ICONFIGPARSER_H
#define AP_PACMAN_ICONFIGPARSER_H
#include <string>
#include <memory>
#include <map>

namespace renderer {

    /**
     * Interface for configuration parser, responsible for loading and retrieving configuration settings.
     */
    class IConfigParser {
    public:
        virtual ~IConfigParser() = default;
        virtual void loadConfigFile() = 0;
        [[nodiscard]] virtual std::string getDefaultFontPath() const = 0;
        [[nodiscard]] virtual std::string getSpriteSheetPath() const = 0;
        [[nodiscard]] virtual std::map<std::string, sf::IntRect> getTextureRects() const = 0;
        [[nodiscard]] virtual sf::IntRect getTextureRectByName(const std::string& name) const =0;
    };
}
#endif //AP_PACMAN_ICONFIGPARSER_H
