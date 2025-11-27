//
// Created by runes on 3/11/2025.
//

#include "game/states/menu/MenuState.h"
#include "core/handlers/IDrawHandler.h"
#include "core/states/IStateInputHandler.h"
#include "core/states/IStateUpdateHandler.h"

namespace renderer {
    MenuState::MenuState(std::unique_ptr<IStateUpdateHandler<MenuState>> &&updateHandler, std::unique_ptr<IStateInputHandler<MenuState>> &&inputHandler,
                         std::unique_ptr<IStateDrawHandler<MenuState>>&& drawHandler) : DelegatingState(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler)) {

    }

} // renderer