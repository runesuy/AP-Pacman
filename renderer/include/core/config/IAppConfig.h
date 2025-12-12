//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IAPPCONFIG_H
#define AP_PACMAN_IAPPCONFIG_H
#include "core/factories/IFactoryCollection.h"
#include "core/parser/IConfigParser.h"
#include "core/parser/ITextureParser.h"

namespace renderer {
    /**
     * Interface for application configuration, providing access to factory collection,
     * configuration parser, and logic configuration.
     *
     * When modifying the game with custom classes, default classes can be overridden by implementing this interface.
     */
    class IAppConfig {
    public:
        /**
         * Get the factory collection used for creating various game components.
         * @note This method is only used on the representation side.
         * @return
         */
        virtual IFactoryCollection &getFactoryCollection() = 0;

        /**
         * Get the configuration parser for reading and interpreting configuration files.
         * @return
         */
        [[nodiscard]] virtual const IConfigParser &getConfigParser() const = 0;

        /**
         * Get the configuration parser for reading and interpreting configuration files.
         * @return
         */
        [[nodiscard]] virtual IConfigParser &getConfigParser() = 0;

        /**
         * Get the logic configuration containing game logic settings.
         * @return
         */
        [[nodiscard]] virtual const logic::IConfig &getLogicConfig() const =0;

        /**
         * Get the logic configuration containing game logic settings.
         * @return
         */
        [[nodiscard]] virtual logic::IConfig &getLogicConfig() =0;

        /**
         * @return The texture parser for loading textures.
         */
        [[nodiscard]] virtual const ITextureParser &getTextureParser() const =0;

        /**
        * @return The texture parser for loading textures.
        */
        [[nodiscard]] virtual ITextureParser &getTextureParser() =0;

        virtual ~IAppConfig() = default;
    };
}
#endif //AP_PACMAN_IAPPCONFIG_H