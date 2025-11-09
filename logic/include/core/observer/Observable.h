//
// Created by runes on 4/11/2025.
//

#ifndef AP_PACMAN_OBSERVABLE_H
#define AP_PACMAN_OBSERVABLE_H


#include <memory>
#include <vector>
#include "IObserver.h"

namespace logic {

    /**
     * An class containing observing logic for integrating with the IObserver class.
     */
    template <typename T>
    class Observable {

        /**
         * List of observers observing this observable
         */
        std::vector<std::shared_ptr<IObserver<T>>> _observers;

    public:
        enum EventType {};

        /**
         * Call update in all observers.
         */
        void updateObservers() {
            for (auto &observer: _observers) {
                observer->update(static_cast<T&>(*this));
            }
        };
        virtual ~Observable();

        /**
         * Add an observer to this observable.
         * @param observer The observer to add
         */
        void addObserver(const std::shared_ptr<IObserver<T>>& observer) { _observers.push_back(observer); };

    };

    template<typename T>
    Observable<T>::~Observable() {
        for (auto &observer: _observers) {
            observer->onObservableDestroyed(static_cast<T&>(*this));
        }
    }
}


#endif //AP_PACMAN_OBSERVABLE_H
