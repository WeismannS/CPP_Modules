#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}


void HumanA::attack()
{
    if (this->weapon.getType().empty())
        std::cout << this->name << "attacks with his bare hands" << std::endl;
    else
        std::cout << this->name << "attacks with his " << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}
