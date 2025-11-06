//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_ENTITYVIEW_H
#define AP_PACMAN_ENTITYVIEW_H
#include "observer/IObserver.h"
#include "entity/EntityModel.h"
#include "drawable/DrawObject.h"

namespace renderer {
    class EntityView : public DrawObject{
        logic::Size size={0,0};
    public:
        [[nodiscard]] const logic::Size &getSize() const;

        void setSize(const logic::Size &size);
    };
}


#endif //AP_PACMAN_ENTITYVIEW_H
