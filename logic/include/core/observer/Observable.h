//
// Created by runes on 4/11/2025.
//

#ifndef AP_PACMAN_OBSERVABLE_H
#define AP_PACMAN_OBSERVABLE_H


#include <memory>
#include <vector>
#include "IObserver.h"
#include "ObservableTypes.h"

namespace logic {
    /**
     * An class containing observing logic for integrating with the IObserver class.
     * An IObservers can be added to the observable list so they are called on certain changes the observable chooses.
     * @tparam Derived The derived class which inherits from Observable.
     */
    template<typename Derived>
    class Observable {
        /**
         * List of observers observing this observable
         */
        std::vector<std::shared_ptr<IObserver<Derived> > > _observers;

    public:
        virtual ~Observable();

        /**
         * Call update in all observers.
         */
        void updateObservers();

        /**
         * Update all observers with an event.
         * @param event String event passed to observers.
         */
        void updateObservers(ObservableTypes::EventType event);

        /**
         * Add an observer to this observable.
         * The observer will be updated on updateObservers(...)
         * @param observer The observer to add
         */
        void addObserver(const std::shared_ptr<IObserver<Derived> > &observer);

        /**
         * @return true if this has any observers
         */
        [[nodiscard]] bool hasObservers() const;

        /**
         * @param observer The observer instance to search for.
         * @return true if observer is among observers
         */
        bool hasObserver(const std::shared_ptr<IObserver<Derived> > &observer) const;
    };


    //---------------------- Implementation ------------------------//

    template<typename Derived>
    void Observable<Derived>::updateObservers() {
        for (auto &observer: _observers) {
            observer->update(static_cast<Derived &>(*this));
        }
    }

    template<typename Derived>
    void Observable<Derived>::updateObservers(ObservableTypes::EventType event) {
        for (auto &observer: _observers) {
            observer->update(static_cast<Derived &>(*this), event);
        }
    }

    template<typename Derived>
    bool Observable<Derived>::hasObservers() const {
        return !_observers.empty();
    }

    template<typename Derived>
    Observable<Derived>::~Observable() {
        for (auto &observer: _observers) {
            observer->onObservableDestroyed(static_cast<Derived &>(*this));
        }
        _observers.clear();
    }

    template<typename Derived>
    bool Observable<Derived>::hasObserver(const std::shared_ptr<IObserver<Derived> > &observer) const {
        for (const auto &obs: _observers) {
            if (obs == observer) {
                return true;
            }
        }
        return false;
    }

    template<typename Derived>
    void Observable<Derived>::addObserver(const std::shared_ptr<IObserver<Derived> > &observer) {
        _observers.push_back(observer);
        updateObservers();
    }
}


#endif //AP_PACMAN_OBSERVABLE_H
