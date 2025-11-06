//
// Created by runes on 3/11/2025.
//

#include "../../../include/states/menu/MenuState.h"
#include "core/IDrawHandler.h"
#include "states/IStateInputHandler.h"
#include "states/IStateUpdateHandler.h"

namespace renderer {
    MenuState::MenuState(std::unique_ptr<IStateUpdateHandler> &&updateHandler, std::unique_ptr<IStateInputHandler> &&inputHandler,
                         std::unique_ptr<logic::IDrawHandler>&& drawHandler) : DelegatingState(std::move(updateHandler), std::move(inputHandler), std::move(drawHandler)) {

    }

} // renderer