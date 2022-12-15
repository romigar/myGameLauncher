#ifndef SQUAREJOKER_H
#define SQUAREJOKER_H

#include <QObject>

class squareJoker
{

public:
    squareJoker();

    bool isActivated;
    std::vector<std::string> squareList;

    void activateSquareJoker(std::string ans1, std::string ans2, std::string ans3, std::string ans4);
    void generateList(std::string ans1, std::string ans2, std::string ans3, std::string ans4);
    void setActivated(const bool active);
    bool getActivated(void) const;

};

#endif // SQUAREJOKER_H
