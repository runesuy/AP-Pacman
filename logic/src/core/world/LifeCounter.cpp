//
// Created by runes on 21/11/2025.
//

#include "core/world/LifeCounter.h"
#include "game/entities/ObserverEvents.h"
#include <algorithm>

namespace logic
{
    unsigned int LifeCounter::getLifeStart()
    {
        return lifeStart;
    }

    unsigned int LifeCounter::getLivesLeft() const
    {
        return livesLeft;
    }

    void LifeCounter::addLives(const unsigned int amount)
    {
        if (amount + livesLeft > lifeStart) livesLeft = lifeStart;
        else livesLeft += amount;
        updateObservers();
    }

    void LifeCounter::removeLives(const unsigned int amount)
    {
        if (livesLeft < amount) livesLeft = 0;
        else livesLeft -= amount;
        updateObservers();
    }

    void LifeCounter::setLivesLeft(unsigned int livesLeft)
    {
        LifeCounter::livesLeft = livesLeft;
        updateObservers();
    }

    void LifeCounter::processEvent(const ObservableTypes::EventType event)
    {
        if (event == ObserverEvents::PLAYER_KILLED)
        {
            removeLives(1);
        }
    }
} // logic
