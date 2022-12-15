#include <iostream>
#include "continent.h"
#include "country.h"

//Default constructor
continent::continent(void)
{

}

/* ***************************************************************** */

//Copy constructor
continent::continent(const continent& other)
{
    setId(other.id);
    setName(other.name);
    list = other.list;
}

/* ***************************************************************** */

// Init Constructor
continent::continent(std::string _name, uint8_t _id)
{
    setId(_id);
    setName(_name);
}

/* ***************************************************************** */

// Init Constructor with filled list
continent::continent(std::string _name, uint8_t _id, std::vector<country> _list)
{
    setId(_id);
    setName(_name);
    list = _list;
}

/* ***************************************************************** */

// geter and seter method
inline uint8_t continent::getId(void) const{   return id;  }
inline void continent::setId(const uint8_t newId){    id = newId;  }
inline std::string continent::getName (void) const{    return name; }
inline void continent::setName(const std::string newName){    name = newName;  }

/* ***************************************************************** */

void continent::display(void)
{
    std::cout<<"Continent: { ";
    std::cout<<"  name :"<< getName() <<","<<std::endl;
    std::cout<<"  id :"<< +getId() <<","<<std::endl;
    std::cout<<"  nb_countries :"<< list.size() <<","<<std::endl;
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */

void continent::display_list(void)
{
    std::cout<<"Continent list : {";
    for (int i = 0; i < list.size(); i++)
    {
        list.at(i).display();
        std::cout<<","<<std::endl;
    }
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */

void continent::display_list_country_name(void)
{
    std::cout<<"Continent list : { "<<std::endl;
    for (int i = 0; i < list.size(); i++)
    {
        list.at(i).display_name();
    }
    std::cout<<"}"<<std::endl;
}

/* ***************************************************************** */
