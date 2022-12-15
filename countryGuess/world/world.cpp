#include <QObject>
#include <QFile>
#include <QDebug>
#include <iostream>
#include <vector>
#include "world.h"
#include "country.h"
#include "continent.h"

/* ***************************************************************** */
/*
 * Extract countries list from a csv file, with format is :
 * country,capital,continent
 * */
void fill_from_csv(std::vector<country> *_countryList)
{
    // Location file
    QFile envFile(":/countryGuess/ressources/liste.csv");
    int i = 0 ; //country counter
    if (envFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&envFile);
        while (!in.atEnd()) // For each line, put a country in countryList
        {
            QString line = in.readLine();
            QStringList list = line.split(',');
            std::string _country = list.at(0).toStdString();
            std::string _capital = list.at(1).toStdString();
            std::string _continent = list.at(2).toStdString();
            _countryList->push_back(*new country(i,_country,_continent,_capital));
            i++;
        }
        envFile.close(); // Close the file
    }
    else {
        std::cout<<  "can not open file"<<std::endl;
    }
}

/* ***************************************************************** */
/*
 * From a countryList, fill a continentList
 * Read "continent" attribute for each country in the list and put it
 * in right continent.countrylist
 * Create a new continent each time a new continent-name is met
 * */
void fillList(std::vector<country> countrylist,std::vector<continent> *_continentList)
{
    bool known_region = false;
    _continentList->clear(); // Clear the continentList
    // Create a first continent for the firt country met and put it in
    std::vector<std::vector<country>> newContList;
    std::vector<country> first;
    first.push_back(countrylist.at(0));
    newContList.push_back(first);

    for (int i = 1 ; i  < countrylist.size() ; i++) {
        known_region = false;
        // Test if this country's continent is already created, is yes, put it in
        for (int k = 0; k < newContList.size(); k++) {
            if (!countrylist.at(i).getContinent().compare( newContList.at(k).at(0).getContinent() ) ) {
                newContList.at(k).push_back(countrylist.at(i));
                known_region = true;
            }
        }
        // if this continent has not been created, then create it, and put the country in
        if (!known_region) {
            std::vector<country> newContinent;
            newContinent.push_back(countrylist.at(i));
            newContList.push_back(newContinent);
        }
    }
    _continentList->push_back(*new continent("Monde",0,countrylist));
    // Init the continentList with the created lists
    for (int k = 0; k < newContList.size(); k++) {
        _continentList->push_back(*new continent(newContList.at(k).at(0).getContinent(),k+1,newContList.at(k)));
    }
}

/* ***************************************************************** */

/*
 * Read csv file to fill countryList
 * than sort this countryList for filling continentList
 * */
void world::fillContinentList(void)
{
    fill_from_csv(&countryList);
    fillList(countryList,&continentList);
}

/* ***************************************************************** */

// Default constructor
world::world()
{
    fillContinentList();
}

/* ***************************************************************** */

world::world(std::vector<continent> _continentList)
{
    continentList = _continentList;
}

/* ***************************************************************** */

world::world(std::vector<country> _countryList, std::vector<continent> _continentList)
{
    continentList = _continentList;
    countryList = _countryList;
}

/* ***************************************************************** */

world::world(std::vector<country> _countryList)
{
    countryList = _countryList;
}

/* ***************************************************************** */

void world::display(void)
{
    std::cout<<"World: { ";
    std::cout<<"  Countries:"<< countryList.size() <<","<<std::endl;
    std::cout<<"  Continents :"<< continentList.size() <<","<<std::endl;
    std::cout<<"  Continents:"<< countryList.size() <<"["<<std::endl;
    for (int i = 0 ; i < continentList.size();i++) {
        continentList.at(i).display();
    }
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */



