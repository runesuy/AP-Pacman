//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_IOBSERVER_H
#define AP_PACMAN_IOBSERVER_H

namespace logic {
    template <typename T>
    /**
     * A default observer class.
     * @tparam T the class this observer observes
     */
    class IObserver{
    public:
        virtual void update(T* subject) const=0;
    };
}


#endif //AP_PACMAN_IOBSERVER_H
