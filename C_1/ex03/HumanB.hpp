#ifndef HUMAN_B_HPP

#define HUMAN_B_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private :
        std::string name;
        Weapon *weapon;
    public :
        HumanB(std::string name);
        HumanB(std::string name, Weapon *weapon);
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif