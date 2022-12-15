#include <QCoreApplication>
#include <QDebug>
#include <QQueue>
#include <QFile>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

#include "city.h"
#include "country.h"
#include "continent.h"
#include "world.h"


void read_file(std::vector<country> *countrylist)
{
    QFile envFile("/home/theo/workspace/countryGuess/ressources/liste.csv");
    int i = 0 ;
    if (envFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&envFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList list = line.split(',');
            std::string _country = list.at(0).toStdString();
            std::string _capital = list.at(1).toStdString();
            std::string _continent = list.at(2).toStdString();
            countrylist->push_back(*new country(i,_country,_continent,_capital));
            std::cout<< +countrylist->at(i).getId() << "\t"
                     << countrylist->at(i).getName() << "\t"
                     << countrylist->at(i).capital->getName() << "\t"
                     << countrylist->at(i).getContinent() << "\t"
                     <<std::endl;
            i++;
        }
        envFile.close();
        std::cout<<  "Init list finished. Size : " << countrylist->size() <<std::endl;
    }
    else {
        std::cout<<  "can not open file"<<std::endl;
    }
}
/*
void fillContinentList(std::vector<country> countrylist,std::vector<continent> *_continentList)
{
    _continentList->clear();
    std::vector<country> europe;
    std::vector<country> asia;
    std::vector<country> america;
    std::vector<country> africa;
    std::vector<country> oceania;
    for (int i = 0 ; i  < countrylist.size() ; i++) {
        if ( !countrylist.at(i).getContinent().compare("Europe") ) {
            europe.push_back(countrylist.at(i));
        }
        else if (!countrylist.at(i).getContinent().compare("Asie") ) {
            asia.push_back(countrylist.at(i));
        }
        else if (!countrylist.at(i).getContinent().compare("Amérique") ) {
            america.push_back(countrylist.at(i));
        }
        else if (!countrylist.at(i).getContinent().compare("Afrique") ) {
            africa.push_back(countrylist.at(i));
        }
        else if (!countrylist.at(i).getContinent().compare("Océanie") ) {
            oceania.push_back(countrylist.at(i));
        }
    }
    _continentList->push_back(*new continent("Europe",0,europe));
    _continentList->push_back(*new continent("Asie",1,asia));
    _continentList->push_back(*new continent("Amérique",2,america));
    _continentList->push_back(*new continent("Afrique",3,africa));
    _continentList->push_back(*new continent("Océanie",4,oceania));
}
*/
/*
void fillList(std::vector<country> countrylist,std::vector<continent> *_continentList)
{
    bool known_region = false;
    _continentList->clear();
    std::vector<std::vector<country>> newContList;
    std::vector<country> first;
    first.push_back(countrylist.at(0));
    newContList.push_back(first);

    for (int i = 1 ; i  < countrylist.size() ; i++) {
        known_region = false;
        for (int k = 0; k < newContList.size(); k++) {
            if (!countrylist.at(i).getContinent().compare( newContList.at(k).at(0).getContinent() ) ) {
                newContList.at(k).push_back(countrylist.at(i));
                known_region = true;
            }
        }
        if (!known_region) {
            std::vector<country> newContinent;
            newContinent.push_back(countrylist.at(i));
            newContList.push_back(newContinent);
        }
    }
    for (int k = 0; k < newContList.size(); k++) {
        _continentList->push_back(*new continent(newContList.at(k).at(0).getContinent(),k,newContList.at(k)));
    }
}
*/


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<< "start test liste"<<std::endl;

    QQueue<int> myqueue;


    std::cout<< "size : "<< myqueue.size()<<std::endl;
    std::cout<< "size : "<< myqueue.empty()<<std::endl;
    uint32_t length ;
    length = 96;

    if (myqueue.size() > length){
        std::cout<< "size : "<< myqueue.size()<<std::endl;


    }
    else {
        std::cout<< "ok : "<< myqueue.size()<<std::endl;

    }

    std::cout<< "finish : "<< myqueue.size()<<std::endl;

    return a.exec();
}

