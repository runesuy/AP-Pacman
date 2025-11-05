//
// Created by rune-suy on 11/5/25.
//

#include "config/DefaultAppConfig.h"

namespace renderer {
    IFactoryCollection &DefaultAppConfig::getFactoryCollection() {
        return factoryCollection;
    }

    IConfigParser &DefaultAppConfig::getConfigParser(){
        return configParser;
    }
} // renderer