//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_ICONFIGPARSER_H
#define AP_PACMAN_ICONFIGPARSER_H
#include <string>
#include <memory>

namespace renderer {
    class IConfigParser {
    public:
        virtual ~IConfigParser() = default;
        virtual void loadConfigFile() = 0;
        virtual std::string getDefaultFontPath() = 0;
    };
}
#endif //AP_PACMAN_ICONFIGPARSER_H
