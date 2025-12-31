//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ITEXTUREPARSER_H
#define AP_PACMAN_ITEXTUREPARSER_H

#include <map>
#include <SFML/Graphics/Texture.hpp>

namespace renderer
{
    class ITextureParser
    {
    public:
        virtual ~ITextureParser() = default;

        /**
         * Parse the textures from the given path using the provided texture rectangles and store them internally.
         * @param path
         * @param textureRects
         */
        virtual void loadTextures(const std::string& path, const std::map<std::string, sf::IntRect>& textureRects) =0;

        /**
         * Get the texture associated with the given name.
         * @param name
         * @return
         */
        [[nodiscard]] virtual const sf::Texture& getTexture(const std::string& name) const = 0;
    };
}


#endif //AP_PACMAN_ITEXTUREPARSER_H
