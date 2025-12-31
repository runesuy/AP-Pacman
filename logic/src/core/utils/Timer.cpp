//
// Created by runes on 27/11/2025.
//

#include "core/utils/Timer.h"

namespace logic
{
    Stopwatch::Timer::Timer(const Stopwatch::TimeType totalTime) : totalTime(totalTime), timeLeft(totalTime)
    {
    }

    void Stopwatch::Timer::start()
    {
        running = true;
        timeLeft = totalTime;
    }

    void Stopwatch::Timer::stop()
    {
        running = false;
    }

    bool Stopwatch::Timer::isCompleted() const
    {
        return timeLeft <= 0;
    }

    bool Stopwatch::Timer::isRunning() const
    {
        return running;
    }

    void Stopwatch::Timer::tick()
    {
        if (running && !isCompleted())
        {
            timeLeft -= getInstance()->getDeltaTime();
        }
        else
        {
            stop();
        }
    }
} // logic
