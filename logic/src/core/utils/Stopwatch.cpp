//
// Created by runes on 3/11/2025.
//

#include "core/utils/Stopwatch.h"
#include "core/utils/Timer.h"

using namespace std::chrono;

void logic::Stopwatch::tick() noexcept {
    time_point<high_resolution_clock, high_resolution_clock::duration> newTime = high_resolution_clock::now();

    if (_firstTick) {
        _firstTick = false;
        _previous = newTime;
        return;
    } else {
        using DoubleSeconds = std::chrono::duration<float>;
        auto elapsed_duration = newTime - _previous;
        deltaTime = std::chrono::duration_cast<DoubleSeconds>(elapsed_duration).count();
    }
    _previous = newTime;

    for (const auto &timer: _timers) {
        timer->tick();
    }
}

logic::Stopwatch::TimeType logic::Stopwatch::getDeltaTime() const noexcept {
    return deltaTime;
}

std::shared_ptr<logic::Stopwatch> logic::Stopwatch::getInstance() {
    if (!_instance) {
        _instance = std::shared_ptr<Stopwatch>(new Stopwatch());
    }
    return _instance;
}

void logic::Stopwatch::addTimer(const std::shared_ptr<Timer> &timer) const {
    _timers.push_back(timer);
}