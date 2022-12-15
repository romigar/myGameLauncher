#include <iostream>
#include "country.h"
#include "city.h"

country::country()
{
}

/* ***************************************************************** */

country::country(const country& other)
    : capital(new city(*other.capital))
{
    setId(other.id);
    setName(other.name);
    setPopulation(other.population);
    setContinent(other.continent);
}

/* ***************************************************************** */

country::country(uint8_t _id, std::string _name, uint32_t _population,
                 std::string _continent, city capital)
    : capital(new city(capital))
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
    setContinent(_continent);
}

/* ***************************************************************** */

country::country(uint8_t _id, std::string _name, std::string _continent, std::string _capital)
    : capital(new city(_id,_capital,0))
{
    setId(_id);
    setName(_name);
    setPopulation(0);
    setContinent(_continent);
}

/* ***************************************************************** */

country::~country()
{
}

/* ***************************************************************** */

inline uint8_t country::getId(void) const{   return id;  }
inline void country::setId(const uint8_t newId){    id = newId;  }
inline std::string country::getName(void) const{    return name; }
inline void country::setName(const std::string newName){    name = newName;  }
inline uint32_t country::getPopulation(void) const{  return population;  }
inline void country::setPopulation(const uint32_t newPopulation){    population = newPopulation; }
inline std::string country::getContinent(void) const{    return continent;   }
inline void country::setContinent(const std::string newContinent){   continent = newContinent;   }
inline uint8_t country::getContinentId(void) const{    return continentId;   }
inline void country::setContinentId(const uint8_t newContinentId){   continentId = newContinentId;   }

/* ***************************************************************** */

void country::display(void)
{
    std::cout<<"Country:{ ";
    std::cout<<"  name : "<< getName() <<","<<std::endl;
    std::cout<<"  population : "<< getPopulation() <<","<<std::endl;
    std::cout<<"  id : "<< +getId() <<","<<std::endl;
    std::cout<<"  continent : "<< getContinent() <<","<<std::endl;
    std::cout<<"  continentId : "<< +getContinentId() <<","<<std::endl;
    std::cout<<"  capital : ";
    this->capital->display();
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */

void country::display_name(void)
{
    std::cout<<getName()<<std::endl;
}
