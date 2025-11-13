//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_ITEXTUREPARSER_H
#define AP_PACMAN_ITEXTUREPARSER_H


#include <SFML/Graphics/Sprite.hpp>
#include <map>
#include <SFML/Graphics/Texture.hpp>

namespace renderer {
    class ITextureParser {

    public:
        virtual void loadTextures(const std::string& path, const std::map<std::string, sf::IntRect>& textureRects)=0;

        [[nodiscard]] virtual const sf::Texture& getTexture(const std::string &name) const = 0;
    };
}


#endif //AP_PACMAN_ITEXTUREPARSER_H
