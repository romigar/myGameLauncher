#ifndef CONTINENT_H
#define CONTINENT_H

#include <QObject>
#include <vector>
#include "country.h"

class country;

class continent
{
public:
    continent();
    continent(const continent&);
    continent(std::string _name, uint8_t _id);
    continent(std::string _name, uint8_t _id, std::vector<country> _list);

    std::vector<country> list;
    std::string name;
    uint8_t id;

    uint8_t getId(void) const;
    void setId(const uint8_t newId);
    std::string getName(void) const;
    void setName(const std::string newName);

    void display(void);
    void display_list(void);
    void display_list_country_name(void);

private:

};

#endif // CONTINENT_H
