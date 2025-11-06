//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DEFAULTAPPCONFIG_H
#define AP_PACMAN_DEFAULTAPPCONFIG_H

#include "IAppConfig.h"
#include "factories/DefaultFactoryCollection.h"
#include "parser/JSONConfigParser.h"
#include "DefaultLogicConfig.h"

namespace renderer {

    class DefaultAppConfig : public IAppConfig{
        DefaultFactoryCollection factoryCollection;
        JSONConfigParser configParser;
        DefaultLogicConfig logicConfig;
    public:
        IFactoryCollection &getFactoryCollection() override;

        IConfigParser &getConfigParser() override;

        logic::IConfig &getLogicConfig() override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTAPPCONFIG_H
