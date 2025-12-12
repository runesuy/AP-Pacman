//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ICONFIGPARSER_H
#define AP_PACMAN_ICONFIGPARSER_H
#include <string>
#include <map>

namespace renderer {
    /**
     * Interface for configuration parser, responsible for loading and retrieving configuration settings.
     */
    class IConfigParser {
    public:
        virtual ~IConfigParser() = default;

        /**
         * Parse the config file and store the data internally.
         */
        virtual void loadConfigFile() = 0;

        /**
         * @return The default font path as specified in the configuration.
         */
        [[nodiscard]] virtual std::string getDefaultFontPath() const = 0;

        /**
         * @return The sprite sheet path as specified in the configuration.
         */
        [[nodiscard]] virtual std::string getSpriteSheetPath() const = 0;

        /**
         * @return The map of texture rectangle names to their corresponding sf::IntRect values as specified in the configuration.
         */
        [[nodiscard]] virtual std::map<std::string, sf::IntRect> getTextureRects() const = 0;

        /**
         * @param name A specific texture rectangle based on a name that is present in the configuration.
         * @return
         */
        [[nodiscard]] virtual sf::IntRect getTextureRectByName(const std::string &name) const =0;
    };
}
#endif //AP_PACMAN_ICONFIGPARSER_H
