//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_LABEL_H
#define AP_PACMAN_LABEL_H
#include "core/drawable/DrawObject.h"

namespace renderer {

    /**
     * A simple UI label for displaying text.
     */
    class Label : public DrawObject {
        sf::Font font;
        sf::Text text;
    public:
        Label();
        explicit Label(const std::string &str);
        Label(const std::string &str, const sf::Font &font);

        void setString(const std::string &str);
        void setFont(const sf::Font &font);
        void setCharacterSize(unsigned int size);

        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow &window) override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts() override;
    };

} // renderer

#endif //AP_PACMAN_LABEL_H
