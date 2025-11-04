//
// Created by runes on 4/11/2025.
//

#include "observer/IObservable.h"

void logic::IObservable::updateObservers() {
    for (auto& observer : _observers) {
        observer->update(std::shared_ptr<IObservable>(this));
    }
}
