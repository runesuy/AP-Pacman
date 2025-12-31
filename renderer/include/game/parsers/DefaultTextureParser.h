//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_DEFAULTTEXTUREPARSER_H
#define AP_PACMAN_DEFAULTTEXTUREPARSER_H

#include <string>
#include "core/parser/ITextureParser.h"

namespace renderer
{
    class DefaultTextureParser : public ITextureParser
    {
        std::map<std::string, sf::Texture> _textureCache;

    public:
        [[nodiscard]] const sf::Texture& getTexture(const std::string& name) const override;

        void loadTextures(const std::string& path, const std::map<std::string, sf::IntRect>& textureRects) override;
    };
} // renderer

#endif //AP_PACMAN_DEFAULTTEXTUREPARSER_H
