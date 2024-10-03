#include "HumanB.hpp"




void HumanB::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}


HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {}


HumanB::HumanB(std::string name, Weapon *weapon) : name(name),weapon(weapon) {}
