#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include <vector>

class country;
class continent;

class world
{
public:
    world();
    world(std::vector<continent> _continentList);
    world(std::vector<country> _countryList);
    world(std::vector<country> _countryList, std::vector<continent> _continentList);
    std::vector<country> countryList;
    std::vector<continent> continentList;

    void fillContinentList(void);

    void display();

private:

};

#endif // WORLD_H
