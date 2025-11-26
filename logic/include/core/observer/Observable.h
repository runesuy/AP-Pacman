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
        using EventType = int;

        /**
         * Call update in all observers.
         */
        void updateObservers() {
            for (auto &observer: _observers) {
                observer->update(static_cast<T&>(*this));
            }
        };

        /**
         * Update all observers with an event.
         * @param event String event passed to observers.
         */
        void updateObservers(EventType event);

        virtual ~Observable();

        /**
         * Add an observer to this observable.
         * @param observer The observer to add
         */
        void addObserver(const std::shared_ptr<IObserver<T>>& observer) {
            _observers.push_back(observer);
            updateObservers();
        };

        /**
         * @return true if this has any observers
         */
        [[nodiscard]] bool hasObservers() const;

        /**
         * @param observer
         * @return true if observer is among observers
         */
        bool hasObserver(const std::shared_ptr<IObserver<T>>& observer) const;

    };

    //---------------------- Implementation ------------------------//

    template<typename T>
    void Observable<T>::updateObservers(EventType event) {
        for (auto &observer: _observers) {
            observer->update(static_cast<T&>(*this), event);
        }
    }

    template<typename T>
    bool Observable<T>::hasObservers() const {
        return !_observers.empty();
    }

    template<typename T>
    Observable<T>::~Observable() {
        for (auto &observer: _observers) {
            observer->onObservableDestroyed(static_cast<T&>(*this));
        }
        _observers.clear();
    }

    template<typename T>
    bool Observable<T>::hasObserver(const std::shared_ptr<IObserver<T>> &observer) const {
        for (const auto& obs : _observers) {
            if (obs == observer) {
                return true;
            }
        }
        return false;
    }
}


#endif //AP_PACMAN_OBSERVABLE_H
