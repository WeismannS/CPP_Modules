#include "Weapon.hpp"


Weapon::Weapon(std::string type) : type(type) {};

const std::string& Weapon::getType()
{
    return this->type;
}

Weapon::Weapon() : type("") {};

Weapon::~Weapon()
{
}
void Weapon::setType(std::string type)
{
    this->type = type;
}
