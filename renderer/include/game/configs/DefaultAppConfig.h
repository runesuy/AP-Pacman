//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DEFAULTAPPCONFIG_H
#define AP_PACMAN_DEFAULTAPPCONFIG_H

#include "core/config/IAppConfig.h"
#include "game/factories/DefaultFactoryCollection.h"
#include "game/parsers/JSONConfigParser.h"
#include "DefaultLogicConfig.h"
#include "game/parsers/DefaultTextureParser.h"

namespace renderer {
    class DefaultAppConfig : public IAppConfig {
        DefaultFactoryCollection factoryCollection;
        JSONConfigParser configParser;
        DefaultLogicConfig logicConfig;
        DefaultTextureParser textureParser;

    public:
        IFactoryCollection &getFactoryCollection() override;

        [[nodiscard]] const IConfigParser &getConfigParser() const override;

        IConfigParser &getConfigParser() override;

        [[nodiscard]] const logic::IConfig &getLogicConfig() const override;

        [[nodiscard]] logic::IConfig &getLogicConfig() override;

        [[nodiscard]] const DefaultTextureParser &getTextureParser() const override;

        ITextureParser &getTextureParser() override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTAPPCONFIG_H