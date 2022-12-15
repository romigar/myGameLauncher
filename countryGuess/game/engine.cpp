#include <iostream>
#include <QRandomGenerator>
#include <QList>
#include "engine.h"
#include "gamesettings.h"
#include "world.h"
#include "continent.h"
#include "country.h"
#include "city.h"
#include "squarejoker.h"
#include "tools.h"

using namespace std;


engine::engine(gameSettings *parent)
    : gameSettings(parent)
    , square(new squareJoker())
    , m_world(new world())
    , m_continent(new continent())
    , m_country(new country())
{
    connect(this, SIGNAL(goodAnswer(int)), this, SLOT(onGoodAnswer(int)));
    connect(this, SIGNAL(badAnswer(int)), this, SLOT(onBadAnswer(int)));
    setChrono(0);
    setTimeRemaining(0);
    setCountriesFound(0);
    setScore(0);
    setNewQuestion();
    setQuestionFinished(0);
    setDisplayGood(0);
    setSquareJokerActivated(0);
}

/* ***************************************************************** */

void engine::setNewGame(QString continentName)
{
    std::cout<< "selected: "<<continentName.toStdString()<<std::endl;

    for (int i = 0; i < m_world->continentList.size() ; i++) {
        if (QString::fromStdString(m_world->continentList.at(i).name) == continentName){
            *m_continent = m_world->continentList.at(i);
            break;
        }
    }
    setChrono(0);
    setTimeRemaining(0);
    setCountriesFound(0);
    setScore(0);
    setNewQuestion();
    setQuestionFinished(0);
    setDisplayGood(0);
    setSquareJokerActivated(0);
}

/* ***************************************************************** */

void engine::setNewQuestion(void)
{
    setDisplayGood(0);
    setSquareJokerActivated(0);
    setQuestionFinished(false);
    if (m_continent->list.empty()){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    std::random_shuffle(m_continent->list.begin(),m_continent->list.end());
    *m_country = m_continent->list.back();
    m_continent->list.pop_back();
    setQuestion(QString::fromStdString(m_country->getName()));
    setRightAnswer(QString::fromStdString(m_country->capital->getName()));
    RightAnswerContinent = QString::fromStdString(m_country->getContinent());
}

/* ***************************************************************** */

void engine::onButtonAnswerClicked(QString answer)
{
    std::cout<<"Answer : "<< answer.toStdString() <<std::endl;
    std::cout<<"RightAnswer : "<< rightAnswer.toStdString() <<std::endl;
    setQuestionFinished(true);
    int points = square->getActivated() ? 3 : 5;

    if (validDistance(rightAnswer.toLocal8Bit(),answer.toLocal8Bit(),0.3)) {
        std::cout<<"Bonne réponse"  <<std::endl;
        emit goodAnswer(points);
    }
    else {
        std::cout<<"Mauvaise réponse"  <<std::endl;
        emit badAnswer(points);
    }
}

/* ***************************************************************** */

void engine::onButtonNextClicked(void)
{
    setNewQuestion();
}


void engine::onBadAnswer(int points)
{
    setScore(score-points);
}

/* ***************************************************************** */

void engine::onGoodAnswer(int points)
{
    setScore(score+points);
    setCountriesFound(getCountriesFound()+1);

    //afficher bonne réponse
    setDisplayGood(1);
}

/* ***************************************************************** */

void engine::onButtonNewGameClicked(QString continentName)
{
    setNewGame(continentName);
}

static uint8_t getContinentId(const QString continentName, const world m_world)
{
    for (int i = 0 ; i< m_world.continentList.size(); i++)
    {
        if (QString::fromStdString(m_world.continentList.at(i).getName()) == continentName) {
            return m_world.continentList.at(i).getId();
        }
    }
    return 0;
}

static bool hasDouble4(const QString str1, const QString str2, QString str3, const QString str4)
{
    return ( (str1 == str2) || (str1 == str3) || (str1 == str4) ||
             (str2 == str3) || (str2 == str4) || (str3 == str4));
}

void engine::onJokerAsked(void)
{
    std::cout<<"Joker asked : "<<std::endl;
    setSquareJokerActivated(1);
    // Pick 3 capital from the same continent
    uint8_t id = getContinentId(RightAnswerContinent,*m_world);
    uint8_t size = m_world->continentList.at(id).list.size();
    bool hasDouble = true;
    int i  = std::rand()%size;
    std::string ans1;
    std::string ans2;
    std::string ans3;
    // Check if all 4 answers are different
    while(hasDouble){
        i  = std::rand()%size;
        ans1 = m_world->continentList.at(id).list.at(i).capital->getName();
        i  = std::rand()%size;
        ans2 = m_world->continentList.at(id).list.at(i).capital->getName();
        i  = std::rand()%size;
        ans3 = m_world->continentList.at(id).list.at(i).capital->getName();
        hasDouble = hasDouble4(QString::fromStdString(ans1),QString::fromStdString(ans2)
                            ,QString::fromStdString(ans3),rightAnswer);
    }
    square->activateSquareJoker(ans1,ans2,ans3,rightAnswer.toStdString());

    setSquareAnswer1(QString::fromStdString(square->squareList.at(0)));
    setSquareAnswer2(QString::fromStdString(square->squareList.at(1)));
    setSquareAnswer3(QString::fromStdString(square->squareList.at(2)));
    setSquareAnswer4(QString::fromStdString(square->squareList.at(3)));
}

/* ***************************************************************** */

int engine::getScore(void){ return score; }
int engine::getChrono(void){ return chrono; }
int engine::getTimeRemaining(void){ return timeRemaining; }
int engine::getCountriesFound(void){ return countriesFound; }
QString engine::getRightAnswer(void){ return rightAnswer; }
QString engine::getQuestion(void){ return question; }
QString engine::getSquareAnswer1(void){ return squareAnswer1; }
QString engine::getSquareAnswer2(void){ return squareAnswer2; }
QString engine::getSquareAnswer3(void){ return squareAnswer3; }
QString engine::getSquareAnswer4(void){ return squareAnswer4; }
bool engine::getQuestionFinished(void){ return questionFinished; }
bool engine::getDisplayGood(void){ return displayGood; }
bool engine::getSquareJokerActivated(void){ return squareJokerActivated;}

/* ***************************************************************** */

void engine::setQuestionFinished(bool val)
{
    questionFinished = val;
    emit questionFinishedChanged();
}

/* ***************************************************************** */

void engine::setRightAnswer(QString val)
{
    rightAnswer = val;
    emit rightAnswerChanged();
}

/* ***************************************************************** */

void engine::setQuestion(QString val)
{
    question = val;
    emit questionChanged();
}

/* ***************************************************************** */

void engine::setScore(int val)
{
    score = val;
    emit scoreChanged();
}

/* ***************************************************************** */

void engine::setChrono(int val)
{
    chrono = val;
    emit chronoChanged();
}

/* ***************************************************************** */

void engine::setTimeRemaining(int val)
{
    timeRemaining = val;
    emit timeRemainingChanged();
}

/* ***************************************************************** */

void engine::setCountriesFound(int val)
{
    countriesFound = val;
    emit countriesFoundChanged();
}

/* ***************************************************************** */

void engine::setSquareAnswer1(QString answer)
{
    squareAnswer1 = answer;
    emit squareAnswer1Changed();
}

/* ***************************************************************** */

void engine::setSquareAnswer2(QString answer)
{
    squareAnswer2 = answer;
    emit squareAnswer2Changed();
}

/* ***************************************************************** */

void engine::setSquareAnswer3(QString answer)
{
    squareAnswer3 = answer;
    emit squareAnswer3Changed();
}

/* ***************************************************************** */

void engine::setSquareAnswer4(QString answer)
{
    squareAnswer4 = answer;
    emit squareAnswer4Changed();
}

/* ***************************************************************** */

void engine::setDisplayGood(bool val)
{
    displayGood = val;
    emit displayGoodChanged();
}

/* ***************************************************************** */

void engine::setSquareJokerActivated(bool val)
{
    squareJokerActivated = val;
    emit squareJokerActivatedChanged();
}

/* ***************************************************************** */


