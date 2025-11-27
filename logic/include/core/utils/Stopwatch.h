//
// Created by runes on 3/11/2025.
//

#ifndef AP_PACMAN_STOPWATCH_H
#define AP_PACMAN_STOPWATCH_H
#include "chrono"

namespace logic {
    using namespace std::chrono;

    /**
     * Calculates and holds the time in seconds between the last two ticks.
     * Can be used for dynamic framerates int the game, by using deltaTime provided by Stopwatch.
     */
    class Stopwatch {
    public:
        class Timer;
        /**
         * The type used for displaying the deltaTime and durations
         */
        using TimeType = float;
    private:
        /**
         * Holds the previous tick timepoint.
         */
        time_point<high_resolution_clock, high_resolution_clock ::duration> _previous;

        /**
         * True if this is the first time tick is called.
         */
        bool _firstTick = true;

        /**
         * The time between the last tick and the one before that. In seconds.
         */
        TimeType deltaTime=0;

        /**
         * Timers updated on each tick.
         */
        mutable std::vector<std::shared_ptr<Stopwatch::Timer>> _timers;

        inline static std::shared_ptr<Stopwatch> _instance;
        Stopwatch()=default;

    public:

        /**
         *  Update the deltaTime
         *  Sets deltaTime to the gap in seconds between this and the previous tick.
         *  Updates all timers with deltaTime.
         *  Returns zero first time tick() is called.
         */
        void tick() noexcept;

        /**
         * @return The time between the previous two ticks in seconds. 0 if tick has only been called once.
         */
        [[nodiscard]] TimeType getDeltaTime() const noexcept;

        /**
         * @return The singleton instance.
         */
        static std::shared_ptr<Stopwatch> getInstance();

        /**
         * Add a timer to be updated on each tick.
         */
        void addTimer(const std::shared_ptr<Timer>& timer) const;
    };
}


#endif //AP_PACMAN_STOPWATCH_H
