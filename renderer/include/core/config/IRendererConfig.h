//
// Created by rune-suy on 1/1/26.
//

#ifndef AP_PACMAN_IRENDERERCONFIG_H
#define AP_PACMAN_IRENDERERCONFIG_H
#include "core/factories/IFactoryCollection.h"
#include "core/parser/IConfigParser.h"
#include "core/parser/ITextureParser.h"

namespace renderer
{
    class IRendererConfig
    {
    public:
        virtual ~IRendererConfig() = default;

        /**
         * @return The texture parser for loading textures.
         */
        [[nodiscard]] virtual const ITextureParser& getTextureParser() const =0;

        /**
        * @return The texture parser for loading textures.
        */
        [[nodiscard]] virtual ITextureParser& getTextureParser() =0;

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
        [[nodiscard]] virtual const IConfigParser& getConfigParser() const = 0;

        /**
         * Get the configuration parser for reading and interpreting configuration files.
         * @return
         */
        [[nodiscard]] virtual IConfigParser& getConfigParser() = 0;
    };
} // renderer

#endif //AP_PACMAN_IRENDERERCONFIG_H