//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_IOBSERVER_H
#define AP_PACMAN_IOBSERVER_H
#include "memory"

namespace logic {
    template <typename T>
    /**
     * A default observer class.
     * @tparam T the class this observer observes
     */
class IObserver{
    public:
        virtual ~IObserver()=default;

        /**
         * Called when the subject being observed has changed.
         * @param subject The subject being observed.
         */
        virtual void update(T &subject)=0;

        /**
         * Called when the subject being observed has changed.
         * @param subject The subject being observed.
         * @param event The event the subject passed.
         */
        virtual void update(T &subject, const std::string &event){};

        /**
         * Called when the subject being observed is being destroyed.
         * @param subject The subject being observerd.
         */
        virtual void onObservableDestroyed(T &subject){};
    };
}


#endif //AP_PACMAN_IOBSERVER_H
