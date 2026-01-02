//
// Created by runes on 3/11/2025.
//

#include "core/world/Score.h"

#include "game/entities/ObserverEvents.h"

void logic::Score::update(World& subject)
{
}

void logic::Score::update(World& subject, ObservableTypes::EventType event)
{
    scoreCounter.processEvent(event);
    lifeCounter.processEvent(event);
}


void logic::Score::onTick()
{
    scoreCounter.onTick();
}


const logic::LifeCounter& logic::Score::getLifeCounter() const
{
    return lifeCounter;
}

logic::LifeCounter& logic::Score::getLifeCounter()
{
    return lifeCounter;
}

const logic::ScoreCounter& logic::Score::getScoreCounter() const
{
    return scoreCounter;
}

logic::ScoreCounter& logic::Score::getScoreCounter()
{
    return scoreCounter;
}

float logic::Score::getDifficultyMultiplier() const
{
    return difficultyMultiplier;
}

void logic::Score::increaseDifficultyMultiplier()
{
    difficultyMultiplier += DIFFICULTY_INCREASE;
}
