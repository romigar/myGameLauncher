#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include <QObject>

class gameSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint32_t bestScore READ getBestScore WRITE setBestScore NOTIFY bestScoreChanged)
    Q_PROPERTY(uint32_t timeLimit READ getTimeLimit WRITE setTimeLimit NOTIFY timeLimitChanged)
    Q_PROPERTY(uint8_t countriesTotal READ getCountriesTotal WRITE setCountriesTotal NOTIFY countriesTotalChanged)
    Q_PROPERTY(QString bestScoreName READ getBestScoreName WRITE setBestScoreName NOTIFY bestScoreNameChanged)
    Q_PROPERTY(QString playerName READ getPlayerName WRITE setPlayerName NOTIFY playerNameChanged)

public:
    explicit gameSettings(QObject *parent = nullptr);

    uint32_t bestScore;
    QString bestScoreName;
    QString playerName;
    uint32_t timeLimit;
    uint8_t countriesTotal;
    QString region;

    uint32_t getBestScore(void) const;
    uint32_t getTimeLimit(void) const;
    uint8_t getCountriesTotal(void) const;
    QString getBestScoreName(void) const;
    QString getPlayerName(void) const;
    void setBestScore(const uint32_t val);
    void setTimeLimit(const uint32_t val);
    void setCountriesTotal(const uint8_t val);
    void setBestScoreName(const QString val);
    void setPlayerName(const QString val);

signals:
    void bestScoreChanged();
    void bestScoreNameChanged();
    void playerNameChanged();
    void timeLimitChanged();
    void countriesTotalChanged();

public slots:

};

#endif // GAMESETTINGS_H
