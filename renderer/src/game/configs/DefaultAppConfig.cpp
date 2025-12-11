//
// Created by rune-suy on 11/5/25.
//

#include "game/configs/DefaultAppConfig.h"

namespace renderer {
    IFactoryCollection &DefaultAppConfig::getFactoryCollection() {
        return factoryCollection;
    }

    const IConfigParser & DefaultAppConfig::getConfigParser() const {
        return configParser;
    }

    const logic::IConfig & DefaultAppConfig::getLogicConfig() const {
        return logicConfig;
    }

    logic::IConfig & DefaultAppConfig::getLogicConfig() {
        return logicConfig;
    }

    IConfigParser &DefaultAppConfig::getConfigParser() {
        return configParser;
    }

    const DefaultTextureParser &DefaultAppConfig::getTextureParser() const {
        return textureParser;
    }

    ITextureParser &DefaultAppConfig::getTextureParser() {
        return textureParser;
    }
} // renderer