//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_DEFAULTAPPCONFIG_H
#define AP_PACMAN_DEFAULTAPPCONFIG_H

#include "core/config/IAppConfig.h"
#include "DefaultLogicConfig.h"
#include "DefaultRendererConfig.h"

namespace renderer
{
    class DefaultAppConfig : public IAppConfig
    {
        DefaultLogicConfig logicConfig;
        DefaultRendererConfig rendererConfig;

    public:
        [[nodiscard]] const logic::ILogicConfig& getLogicConfig() const override;

        [[nodiscard]] logic::ILogicConfig& getLogicConfig() override;

        [[nodiscard]] IRendererConfig& getRendererConfig() override;
        [[nodiscard]] const IRendererConfig& getRendererConfig() const override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTAPPCONFIG_H
