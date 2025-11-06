//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DEFAULTAPPCONFIG_H
#define AP_PACMAN_DEFAULTAPPCONFIG_H

#include "IAppConfig.h"
#include "factories/DefaultFactoryCollection.h"
#include "parser/JSONConfigParser.h"
#include "DefaultLogicConfig.h"
#include "parser/DefaultTextureParser.h"

namespace renderer {

    class DefaultAppConfig : public IAppConfig{
        DefaultFactoryCollection factoryCollection;
        JSONConfigParser configParser;
        DefaultLogicConfig logicConfig;
        DefaultTextureParser textureParser;
    public:
        IFactoryCollection &getFactoryCollection() override;

        [[nodiscard]] const IConfigParser & getConfigParser() const override;

        IConfigParser &getConfigParser() override;

        [[nodiscard]] const logic::IConfig & getLogicConfig() const override;

        [[nodiscard]] const DefaultTextureParser &getTextureParser() const override;

        ITextureParser &getTextureParser() override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTAPPCONFIG_H
