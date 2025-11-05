//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DEFAULTAPPCONFIG_H
#define AP_PACMAN_DEFAULTAPPCONFIG_H

#include "IAppConfig.h"
#include "DefaultFactoryCollection.h"
#include "parser/JSONConfigParser.h"

namespace renderer {

    class DefaultAppConfig : public IAppConfig{
        DefaultFactoryCollection factoryCollection;
        JSONConfigParser configParser;
    public:
        IFactoryCollection &getFactoryCollection() override;

        IConfigParser &getConfigParser() override;
    };

} // renderer

#endif //AP_PACMAN_DEFAULTAPPCONFIG_H
