//
// Created by rune-suy on 11/14/25.
//

#include "core/drawable/ui/Label.h"
#include "game/Game.h"
#include "core/utils/Camera.h"
#include "core/utils/Camera.h"

namespace renderer {
    Label::Label() {
        text.setString("Label");
        text.setCharacterSize(14);
        font.loadFromFile(Game::getInstance()->getAppConfig().getConfigParser().getDefaultFontPath());
        text.setFont(font);
    }

    void Label::setString(const std::string &str) {
        text.setString(str);
    }

    Label::Label(const std::string &str) {
        text.setString(str);
        text.setCharacterSize(14);
        font.loadFromFile(Game::getInstance()->getAppConfig().getConfigParser().getDefaultFontPath());
        text.setFont(font);
    }

    Label::Label(const std::string &str, const sf::Font &font) {
        text.setString(str);
        text.setCharacterSize(14);
        this->font = font;
        text.setFont(font);
    }

    void Label::setCharacterSize(float size) {
        characterSize = size;
    }

    void Label::setFont(const sf::Font &font) {
    }

    std::vector<std::unique_ptr<sf::Shape> > Label::getSFShapes(sf::RenderWindow &window) {
        return {};
    }

    std::vector<std::shared_ptr<sf::Sprite> > Label::getSFSprites(sf::RenderWindow &window) {
        return {};
    }

    std::vector<std::unique_ptr<sf::Text> > Label::getSFTexts(sf::RenderWindow &window) {
        std::vector<std::unique_ptr<sf::Text> > texts;
        text.setCharacterSize(Camera::sizeY(characterSize, window));
        _applyOriginProps();
        texts.push_back(std::make_unique<sf::Text>(text));
        return texts;
    }

    void Label::setHorizontalOrigin(Label::HorizontalOriginType horizontalOrigin) {
        Label::horizontalOrigin = horizontalOrigin;
    }

    void Label::_applyOriginProps() const {
        switch (horizontalOrigin) {
            case HorizontalOriginType::LEFT: {
                text.setOrigin(0, text.getOrigin().y);
                break;
            }
            case HorizontalOriginType::MIDDLE: {
                text.setOrigin(text.getLocalBounds().width / 2, text.getOrigin().y);
                break;
            }
            case HorizontalOriginType::RIGHT: {
                text.setOrigin(text.getLocalBounds().width, text.getOrigin().y);
                break;
            }
        }
        switch (verticalOrigin) {
            case VerticalOriginType::TOP: {
                text.setOrigin(text.getOrigin().x, 0);
                break;
            }
            case VerticalOriginType::MIDDLE: {
                text.setOrigin(text.getOrigin().x, text.getLocalBounds().height / 2);
                break;
            }
            case VerticalOriginType::BOTTOM: {
                text.setOrigin(text.getOrigin().x, text.getLocalBounds().height);
                break;
            }
        }
    }

    float Label::getCharacterSize() const {
        return characterSize;
    }

    const std::string::size_type Label::getStringSize() const {
        return text.getString().getSize();
    }

    void Label::setVerticalOrigin(Label::VerticalOriginType verticalOrigin) {
        this->verticalOrigin = verticalOrigin;
    }
} // renderer