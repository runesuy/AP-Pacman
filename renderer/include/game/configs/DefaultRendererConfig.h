//
// Created by rune-suy on 1/1/26.
//

#ifndef AP_PACMAN_DEFAULTRENDERERCONFIG_H
#define AP_PACMAN_DEFAULTRENDERERCONFIG_H
#include "core/config/IRendererConfig.h"
#include "game/factories/DefaultFactoryCollection.h"
#include "game/parsers/DefaultTextureParser.h"
#include "game/parsers/JSONConfigParser.h"

namespace renderer
{
    class DefaultRendererConfig : public IRendererConfig
    {
        DefaultFactoryCollection factoryCollection;
        JSONConfigParser configParser;
        DefaultTextureParser textureParser;

    public:
        ~DefaultRendererConfig() override = default;
        [[nodiscard]] const ITextureParser& getTextureParser() const override;
        [[nodiscard]] ITextureParser& getTextureParser() override;
        IFactoryCollection& getFactoryCollection() override;
        [[nodiscard]] const IConfigParser& getConfigParser() const override;
        [[nodiscard]] IConfigParser& getConfigParser() override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTRENDERERCONFIG_H
