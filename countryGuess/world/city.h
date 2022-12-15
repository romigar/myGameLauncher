#ifndef CITY_H
#define CITY_H

#include <QObject>

class city
{
public:
    city();             // public constructor
    city(const city&);  // public copy constructor
    city(uint8_t _id, std::string _name, uint32_t _population);
    ~city();

    std::string name;
    uint8_t id;
    uint32_t population;

    uint8_t getId(void) const;
    void setId(const uint8_t newId);
    std::string getName(void) const;
    void setName(const std::string newName);
    uint32_t getPopulation(void) const;
    void setPopulation(const uint32_t newPopulation);
    void display();
    void display_name();
private:

};

#endif // CITY_H

