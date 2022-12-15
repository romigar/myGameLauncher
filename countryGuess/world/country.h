#ifndef COUNTRY_H
#define COUNTRY_H

#include <QObject>

class city;

class country
{

public:
    country();
    country(const country&);
    country(uint8_t _id, std::string _name, uint32_t _population,
                     std::string _continent, city capital);
    country(uint8_t _id, std::string _name, std::string _continent, std::string _capital);
    ~country();

    std::string name;
    uint8_t id;
    uint32_t population;
    std::string continent;
    uint8_t continentId;
    city* capital;

    uint8_t getId(void) const;
    void setId(const uint8_t newId);
    std::string getName(void) const;
    void setName(const std::string newName);
    uint32_t getPopulation(void) const;
    void setPopulation(const uint32_t newPopulation);
    std::string getContinent(void) const;
    void setContinent(const std::string newContinent);
    uint8_t getContinentId(void) const;
    void setContinentId(const uint8_t newContinentId);

    void display(void);
    void display_name(void);

private:

};


#endif // COUNTRY_H
