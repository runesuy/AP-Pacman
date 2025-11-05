//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IAPPCONFIG_H
#define AP_PACMAN_IAPPCONFIG_H
#include <string>
#include "IFactoryCollection.h"
#include "parser/IConfigParser.h"

namespace renderer {
    class IAppConfig {
    public:
        virtual IFactoryCollection& getFactoryCollection() = 0;
        virtual IConfigParser& getConfigParser() = 0;

        virtual ~IAppConfig() = default;
    };

}
#endif //AP_PACMAN_IAPPCONFIG_H
