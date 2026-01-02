//
// Created by rune-suy on 1/1/26.
//

#include "game/configs/DefaultRendererConfig.h"

namespace renderer
{
    IFactoryCollection& DefaultRendererConfig::getFactoryCollection()
    {
        return factoryCollection;
    }

    const IConfigParser& DefaultRendererConfig::getConfigParser() const
    {
        return configParser;
    }

    IConfigParser& DefaultRendererConfig::getConfigParser()
    {
        return configParser;
    }

    const ITextureParser& DefaultRendererConfig::getTextureParser() const
    {
        return textureParser;
    }

    ITextureParser& DefaultRendererConfig::getTextureParser()
    {
        return textureParser;
    }
} // renderer
