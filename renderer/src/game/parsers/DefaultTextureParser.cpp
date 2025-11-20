//
// Created by rune-suy on 11/6/25.
//

#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "game/parsers/DefaultTextureParser.h"
#include "game/parsers/JSONConfigParser.h"
#include "game/Game.h"
#include "core/exceptions/InvalidTextureNameException.h"

namespace renderer {

    const sf::Texture& DefaultTextureParser::getTexture(const std::string &name) const {
        try { return _textureCache.at(name); }
        catch (const std::out_of_range& e) {
            throw InvalidTextureNameException(name);
        }
    }

    void DefaultTextureParser::loadTextures(const std::string &path,
                                            const std::map<std::string, sf::IntRect> &textureRects) {

        for (const auto& [name, rect] : textureRects) {
            sf::Texture texture;
            sf::IntRect correctedRect = rect;
            correctedRect.height += 1;
            correctedRect.left-=1;
            if (texture.loadFromFile(path, correctedRect)) {
                _textureCache[name] = texture;
            } else {
                throw std::runtime_error("Failed to load texture: " + name + " from path: " + path);
            }
        }
    }
} // renderer