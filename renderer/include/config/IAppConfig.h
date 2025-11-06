//
// Created by rune-suy on 11/5/25.
//

#ifndef AP_PACMAN_IAPPCONFIG_H
#define AP_PACMAN_IAPPCONFIG_H
#include <string>
#include "factories/IFactoryCollection.h"
#include "parser/IConfigParser.h"

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
        virtual IFactoryCollection& getFactoryCollection() = 0;

        /**
         * Get the configuration parser for reading and interpreting configuration files.
         * @return
         */
        virtual IConfigParser& getConfigParser() = 0;

        /**
         * Get the logic configuration containing game logic settings.
         * @return
         */
        virtual logic::IConfig& getLogicConfig()=0;

        virtual ~IAppConfig() = default;
    };

}
#endif //AP_PACMAN_IAPPCONFIG_H
