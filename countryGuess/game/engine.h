#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include "gamesettings.h"

class gameSettings;
class squareJoker;
class world;
class continent;
class country;

class engine : public gameSettings
{
    Q_OBJECT
    Q_PROPERTY(int score READ getScore WRITE setScore NOTIFY scoreChanged)
    Q_PROPERTY(int chrono READ getChrono WRITE setChrono NOTIFY chronoChanged)
    Q_PROPERTY(int timeRemaining READ getTimeRemaining WRITE setTimeRemaining NOTIFY timeRemainingChanged)
    Q_PROPERTY(int countriesFound READ getCountriesFound WRITE setCountriesFound NOTIFY countriesFoundChanged)
    Q_PROPERTY(QString rightAnswer READ getRightAnswer WRITE setRightAnswer NOTIFY rightAnswerChanged)
    Q_PROPERTY(QString question READ getQuestion WRITE setQuestion NOTIFY questionChanged)
    Q_PROPERTY(bool questionFinished READ getQuestionFinished WRITE setQuestionFinished NOTIFY questionFinishedChanged)
    Q_PROPERTY(bool displayGood READ getDisplayGood WRITE setDisplayGood NOTIFY displayGoodChanged)
    Q_PROPERTY(bool squareJokerActivated READ getSquareJokerActivated WRITE setSquareJokerActivated NOTIFY squareJokerActivatedChanged)


    Q_PROPERTY(QString squareAnswer1 READ getSquareAnswer1 WRITE setSquareAnswer1 NOTIFY squareAnswer1Changed)
    Q_PROPERTY(QString squareAnswer2 READ getSquareAnswer2 WRITE setSquareAnswer2 NOTIFY squareAnswer2Changed)
    Q_PROPERTY(QString squareAnswer3 READ getSquareAnswer3 WRITE setSquareAnswer3 NOTIFY squareAnswer3Changed)
    Q_PROPERTY(QString squareAnswer4 READ getSquareAnswer4 WRITE setSquareAnswer4 NOTIFY squareAnswer4Changed)

public:
    explicit engine(gameSettings *parent = nullptr);

    squareJoker* square;
    world* m_world;
    continent* m_continent;
    country* m_country;
    QString question;
    QString rightAnswer;
    QString RightAnswerContinent;

    int score;
    int chrono;
    int timeRemaining;
    int countriesFound;
    bool questionFinished;
    bool displayGood;
    bool squareJokerActivated;

    QString squareAnswer1;
    QString squareAnswer2;
    QString squareAnswer3;
    QString squareAnswer4;


    int getScore(void);
    int getChrono(void);
    int getTimeRemaining(void);
    int getCountriesFound(void);
    QString getRightAnswer(void);
    QString getQuestion(void);
    void setScore(int val);
    void setChrono(int val);
    void setTimeRemaining(int val);
    void setCountriesFound(int val);
    void setRightAnswer(QString val);
    void setQuestion(QString val);
    QString getSquareAnswer1(void);
    void setSquareAnswer1(QString answer);
    QString getSquareAnswer2(void);
    void setSquareAnswer2(QString answer);
    QString getSquareAnswer3(void);
    void setSquareAnswer3(QString answer);
    QString getSquareAnswer4(void);
    void setSquareAnswer4(QString answer);
    bool getQuestionFinished(void);
    void setQuestionFinished(bool val);
    bool getDisplayGood(void);
    void setDisplayGood(bool val);
    void setSquareJokerActivated(bool val);
    bool getSquareJokerActivated(void);

    void setNewQuestion(void);
    void setNewGame(QString continentName);



signals:
    void goodAnswer(int points);
    void badAnswer(int points);
    void scoreChanged();
    void chronoChanged();
    void timeRemainingChanged();
    void countriesFoundChanged();
    void rightAnswerChanged();
    void questionChanged();
    void squareAnswer1Changed();
    void squareAnswer2Changed();
    void squareAnswer3Changed();
    void squareAnswer4Changed();
    void questionFinishedChanged();
    void displayGoodChanged();
    void squareJokerActivatedChanged();

public slots:
    void onGoodAnswer(int points);
    void onBadAnswer(int points);
    void onJokerAsked(void);
    void onButtonAnswerClicked(QString answer);
    void onButtonNextClicked(void);
    void onButtonNewGameClicked(QString continentName);


private:
};

#endif // ENGINE_H
