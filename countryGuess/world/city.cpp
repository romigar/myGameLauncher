#include <iostream>
#include "city.h"

// constructor
city::city(uint8_t _id, std::string _name, uint32_t _population)
{
    setId(_id);
    setName(_name);
    setPopulation(_population);
}

/* ***************************************************************** */

// Copy constructor
city::city(const city& other)
{
    setName(other.name);
    setPopulation(other.population);
    setId(other.id);
}

/* ***************************************************************** */

//default constructor
city::city(){ }

//default destructor
city::~city(){ }


/* ***************************************************************** */

inline uint8_t city::getId(void) const{   return id;  }
inline std::string city::getName(void) const{   return name;  }
inline uint32_t city::getPopulation(void) const{   return population;  }
inline void city::setPopulation(uint32_t newPopulation){   population = newPopulation;  }
inline void city::setName(std::string newName){   name = newName;  }
inline void city::setId(uint8_t newId){   id = newId;  }

/* ***************************************************************** */

void city::display(void)
{
    std::cout<<"City:{ "<<std::endl;
    std::cout<<"  name : "<< this->getName() <<","<<std::endl;
    std::cout<<"  population : "<< this->getPopulation() <<","<<std::endl;
    std::cout<<"  id : "<< +this->getId() <<std::endl;
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */

void city::display_name(void)
{
    std::cout<<getName()<<std::endl;
}
