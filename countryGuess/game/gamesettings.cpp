#include <QObject>
#include <QDebug>
#include "gamesettings.h"

gameSettings::gameSettings(QObject *parent) : QObject(parent)
{
    setTimeLimit(0);
    setBestScore(0);
    setPlayerName("player1");
    setBestScoreName("");
    setCountriesTotal(0);
}

/* ***************************************************************** */

uint32_t gameSettings::getBestScore(void) const{ return bestScore; }
uint32_t gameSettings::getTimeLimit(void) const{ return timeLimit; }
uint8_t gameSettings::getCountriesTotal(void) const{ return countriesTotal; }
QString gameSettings::getPlayerName(void) const{ return playerName; }
QString gameSettings::getBestScoreName(void) const{ return bestScoreName; }

/* ***************************************************************** */

void gameSettings::setBestScore(const uint32_t val)
{
    bestScore = val;
    emit bestScoreChanged();
}

/* ***************************************************************** */

void gameSettings::setTimeLimit(const uint32_t val)
{
    timeLimit = val;
    emit timeLimitChanged();
}

/* ***************************************************************** */

void gameSettings::setCountriesTotal(const uint8_t val)
{
    countriesTotal = val;
    emit countriesTotalChanged();
}

/* ***************************************************************** */

void gameSettings::setPlayerName(const QString val)
{
    playerName = val;
    emit playerNameChanged();
}

/* ***************************************************************** */

void gameSettings::setBestScoreName(const QString val)
{
    bestScoreName = val;
    emit bestScoreNameChanged();
}

/* ***************************************************************** */
