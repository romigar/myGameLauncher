#include "squarejoker.h"
#include <QRandomGenerator>

squareJoker::squareJoker()
{
    setActivated(0);
}

/* ***************************************************************** */

void squareJoker::generateList(std::string ans1, std::string ans2, std::string ans3, std::string ans4)
{
    squareList.clear();
    squareList.push_back(ans1);
    squareList.push_back(ans2);
    squareList.push_back(ans3);
    squareList.push_back(ans4);
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    std::random_shuffle(squareList.begin(),squareList.end());
}

/* ***************************************************************** */

void squareJoker::setActivated(const bool active) { isActivated = active; }

/* ***************************************************************** */

bool squareJoker::getActivated(void) const { return isActivated; }

/* ***************************************************************** */

void squareJoker::activateSquareJoker(std::string ans1, std::string ans2, std::string ans3, std::string ans4)
{
    generateList(ans1,ans2,ans3,ans4);
    setActivated(true);
}

/* ***************************************************************** */
