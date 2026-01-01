//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IAPPCONFIG_H
#define AP_PACMAN_IAPPCONFIG_H
#include "IRendererConfig.h"
#include "core/config/ILogicConfig.h"
#include "core/factories/IFactoryCollection.h"
#include "core/parser/IConfigParser.h"
#include "core/parser/ITextureParser.h"

namespace renderer
{
    /**
     * Interface for application configuration, providing access to factory collection,
     * configuration parser, and logic configuration.
     *
     * When modifying the game with custom classes, default classes can be overridden by implementing this interface.
     */
    class IAppConfig
    {
    public:
        /**
         * Get the logic configuration containing game logic settings.
         * @return
         */
        [[nodiscard]] virtual const logic::ILogicConfig& getLogicConfig() const =0;

        /**
         * Get the logic configuration containing game logic settings.
         * @return
         */
        [[nodiscard]] virtual logic::ILogicConfig& getLogicConfig() =0;

        /**
         * Get the factory collection for creating various game objects.
         * @return
         */
        [[nodiscard]] virtual IRendererConfig& getRendererConfig() =0;

        /**
         * Get the factory collection for creating various game objects.
         * @return
         */
        [[nodiscard]] virtual const IRendererConfig& getRendererConfig() const =0;


        virtual ~IAppConfig() = default;
    };
}
#endif //AP_PACMAN_IAPPCONFIG_H
