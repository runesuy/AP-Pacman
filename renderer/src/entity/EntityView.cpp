//
// Created by runes on 3/11/2025.
//

#include "../../include/entity/EntityView.h"

const logic::Size &renderer::EntityView::getSize() const {
    return size;
}

void renderer::EntityView::setSize(const logic::Size &size) {
    EntityView::size = size;
}
