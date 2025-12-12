//
// Created by rune-suy on 11/14/25.
//

#ifndef AP_PACMAN_LABEL_H
#define AP_PACMAN_LABEL_H
#include "core/drawable/DrawObject.h"

namespace renderer {
    /**
     * A simple UI victoryLabel for displaying text.
     */
    class Label : public DrawObject {
    public:
        enum class HorizontalOriginType {
            LEFT, MIDDLE, RIGHT
        };

        enum class VerticalOriginType {
            TOP, MIDDLE, BOTTOM
        };

    private:
        sf::Font font;
        mutable sf::Text text;
        float characterSize = 0.05;
        HorizontalOriginType horizontalOrigin = HorizontalOriginType::LEFT;
        VerticalOriginType verticalOrigin = VerticalOriginType::TOP;

        void _applyOriginProps() const;

    public:
        /**
         * Text label with default empty string.
         * Font is default font provided by the renderer Config.
         */
        Label();

        /**
         * @param str The string to display.
         */
        explicit Label(const std::string &str);

        /**
         * @param str The string to display.
         * @param font The font to use.
         */
        Label(const std::string &str, const sf::Font &font);

        /**
         * Set the string to display.
         * @param str
         */
        void setString(const std::string &str);

        /**
         * Set the font to use.
         * @param font
         */
        void setFont(const sf::Font &font);

        /**
         *
         * @param size
         */
        void setCharacterSize(float size);

        /**
         * @return Current character size in logic Size units.
         */
        float getCharacterSize() const;

        /**
         * @return The size of the current string in characters.
         */
        const std::string::size_type getStringSize() const;

        /**
         * Set the horizontal origin of the label.
         * @param horizontalOrigin
         */
        void setHorizontalOrigin(HorizontalOriginType horizontalOrigin);

        /**
         * Set the vertical origin of the label.
         * @param verticalOrigin
         */
        void setVerticalOrigin(VerticalOriginType verticalOrigin);

        std::vector<std::unique_ptr<sf::Shape> > getSFShapes(sf::RenderWindow &window) override;

        std::vector<std::shared_ptr<sf::Sprite> > getSFSprites(sf::RenderWindow &window) override;

        std::vector<std::unique_ptr<sf::Text> > getSFTexts(sf::RenderWindow &window) override;
    };
} // renderer

#endif //AP_PACMAN_LABEL_H
