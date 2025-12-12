//
// Created by rune-suy on 11/6/25.
//

#ifndef AP_PACMAN_MODULARENTITYVIEW_H
#define AP_PACMAN_MODULARENTITYVIEW_H

#include "core/entity/EntityView.h"
#include "IEntityViewModule.h"
#include <vector>

#include "core/observer/Observable.h"

namespace renderer {

    template<typename T>
    concept IsModuleType = std::is_base_of<IEntityViewModule, T>::value;
    class ModularEntityView : public EntityView, public logic::Observable<ModularEntityView> {
        std::vector<std::shared_ptr<IEntityViewModule>> modules;
    public:
        std::vector<std::unique_ptr<sf::Shape>> getSFShapes(sf::RenderWindow &window) override;

        std::vector<std::shared_ptr<sf::Sprite>> getSFSprites(sf::RenderWindow &window) override;

        std::vector<std::unique_ptr<sf::Text>> getSFTexts(sf::RenderWindow &window) override;

        void addModule(std::shared_ptr<IEntityViewModule> module);

        template<IsModuleType T>
        std::shared_ptr<T> getModule() {
            for (const auto& module : modules) {
                if (auto casted = std::dynamic_pointer_cast<T>(module)) {
                    return casted;
                }
            }
            return nullptr;
        };
    };

} // renderer

#endif //AP_PACMAN_MODULARENTITYVIEW_H
