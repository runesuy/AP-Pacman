//
// Created by rune-suy on 11/5/25.
//

#include "game/configs/DefaultAppConfig.h"

namespace renderer
{
    IRendererConfig& DefaultAppConfig::getRendererConfig()
    {
        return rendererConfig;
    }

    const IRendererConfig& DefaultAppConfig::getRendererConfig() const
    {
        return rendererConfig;
    }

    const logic::ILogicConfig& DefaultAppConfig::getLogicConfig() const
    {
        return logicConfig;
    }

    logic::ILogicConfig& DefaultAppConfig::getLogicConfig()
    {
        return logicConfig;
    }
} // renderer
